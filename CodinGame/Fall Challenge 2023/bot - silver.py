from enum import Enum
import sys
import math
from typing import Dict, List, Optional

############### Classes ###############
class Game:
    def __init__(self, max_turns, max_x, max_y):
        self.max_turns = max_turns
        self.max_x = max_x
        self.max_y = max_y
        self.turn = 0
        # drone
        self.drone_dark_scan_range = 800
        self.drone_light_scan_range = 2000
        self.drone_range_light_cost = 5
        self.drone_safe_y = 2500
        self.drone_hitbox = 200
        self.drone_speed = 600
        self.drone_sink = 300
        self.drone_emergency_speed = 300
        self.drone_battery_max = 30
        self.drone_battery_recharge = 1
        self.drone_scan_return = 500
        self.drone_search_range_x = [800, 9200]
        self.drone_escape_range_x = [0, 9999]
        # fish
        self.fish_speed = 200
        self.fish_avoid_range = 600
        self.fish_flee_speed = 400
        self.fish_hearing_range = 1400
        self.fish_escape_x = [0, 9999]
        self.fish_type_0 = FishType(0, 2500, 5000)
        self.fish_type_0_list = [4, 5, 10, 11]
        self.fish_type_1 = FishType(1, 5000, 7500)
        self.fish_type_1_list = [6, 7, 12, 13]
        self.fish_type_2 = FishType(2, 7500, 10000)
        self.fish_type_2_list = [8, 9, 14, 15]
        self.fish_color = [0, 1, 2, 3]
        # monster
        self.monster_hitbox = 300
        self.monster_speed = 270
        self.monster_aggressive_speed = 540
        self.monster_range = 500
        self.monster_reached_range = 1040
        self.monster_avoid_range = 600
        self.monster_scan_range = 2300
        self.monster = FishType(-1, 2500, 10000)
        self.monster_color = -1
        self.monster_min_spawn_y = 5000

class FishType:
    def __init__(self, type_id, min_y, max_y):
        self.type = type_id
        self.min_y = min_y
        self.max_y = max_y

class Creature:
    def __init__(self, creature_id, color, type):
        self.creature_id = creature_id
        self.color = color
        self.type = type

class Fish:
    def __init__(self, id, x, y, vx, vy, color, type):
        self.id = id
        self.color = color
        self.type = type
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy

class Drone:
    def __init__(self, drone_id, x, y, emergency, battery):
        self.drone_id = drone_id
        self.x = x
        self.y = y
        self.emergency = emergency
        self.battery = battery
        self.light = 1
        self.dodge = False
        self.returning = False
        self.message: Optional[str] = None
        self.scans = []
        self.target: Optional[int] = None
        self.target_type: Optional[int] = None
        self.target_color: Optional[int] = None
        self.target_x: Optional[int] = None
        self.target_y: Optional[int] = None
        self.target_vx: Optional[int] = None
        self.target_vy: Optional[int] = None
        self.target_distance: Optional[float] = None
        self.target_direction: Optional[Directions] = None

class Directions(Enum):
    TL = 'TL'
    TR = 'TR'
    BR = 'BR'
    BL = 'BL'

class RadarBlip:
    def __init__(self, creature_id, radar_location):
        self.id = creature_id
        self.radar_location: Optional[Directions] = radar_location

# ? ###############################################################################
# ? ################################## Fishes #####################################
# ? ###############################################################################

def get_type(creature_id, creature_list):
    for creature in creature_list:
        if creature.creature_id == creature_id:
            return creature.type

def get_color(creature_id, creature_list):
    for creature in creature_list:
        if creature.creature_id == creature_id:
            return creature.color

def get_position(fish_id, visible_list):
    for fish in visible_list:
        if fish == fish_id:
            return fish.x, fish.y, fish.vx, fish.vy

def get_distance(x1, y1, x2, y2) -> float:
    return math.sqrt((x2-x1)**2 + (y2-y1)**2)

# * Get direction between two points (from point 1 to point 2)
# @params: x1, y1, x2, y2
# @return: direction (TL, TR, BL, BR)
def get_direction(x1, y1, x2, y2) -> Directions:
    if x1 >= x2:
        if y1 <= y2:
            return Directions.TL
        else:
            return Directions.BL
    else:
        if y1 <= y2:
            return Directions.TR
        else:
            return Directions.BR

# * Get hypothetical position of a fish at the end of the turn
# @params: drone_x, drone_y, radar_location
# @return: x, y (-1, -1 if error)
def get_radar_hypothetical_position(drone_x, drone_y, radar_location: Directions | None) -> tuple[int, int]:
    if radar_location == Directions.TL.value:
        return drone_x - GameInfos.drone_speed, drone_y - GameInfos.drone_speed
    elif radar_location == Directions.TR.value:
        return drone_x + GameInfos.drone_speed, drone_y - GameInfos.drone_speed
    elif radar_location == Directions.BL.value:
        return drone_x - GameInfos.drone_speed, drone_y + GameInfos.drone_speed
    elif radar_location == Directions.BR.value:
        return drone_x + GameInfos.drone_speed, drone_y + GameInfos.drone_speed
    print_debug(f"Error: Radar location {radar_location} not found")
    return -1, -1

# ? ###############################################################################
# ? ################################## Drones #####################################
# ? ###############################################################################

# Check if target exist and is not already scanned or targeted
def check_target(id, drone: Drone, drone_radar_blips: list[RadarBlip], my_scans: list[int], my_drones: list[Drone]) -> bool:
    if get_type(id, Creatures) == -1:
        return False
    if id in my_scans:
        return False
    for iterdrone in my_drones:
        if id in iterdrone.scans:
            return False
        if drone.drone_id != iterdrone.drone_id:
            if iterdrone.target == id:
                return False
    if not any(blip.id == id for blip in drone_radar_blips):
        return False
    return True

# Check if target is in range
def choose_target(drone: Drone, visible_fish: list[Fish], drone_radar_blips: list[RadarBlip], my_scans: list[int], my_drones: list[Drone]):
    closest_fish = None
    min_distance = 1000000
    for fish in visible_fish:
        dist = get_distance(drone.x, drone.y, fish.x, fish.y)
        if dist < min_distance and check_target(fish.id, drone, drone_radar_blips, my_scans, my_drones) == True:
            min_distance = dist
            closest_fish = fish
    if closest_fish != None:
        drone.target = closest_fish.id
        drone.target_type = closest_fish.type
        drone.target_color = closest_fish.color
        drone.target_x = closest_fish.x
        drone.target_y = closest_fish.y
        drone.target_vx = closest_fish.vx
        drone.target_vy = closest_fish.vy
        drone.target_distance = min_distance
        drone.target_direction = get_direction(closest_fish.x, closest_fish.y, closest_fish.vx, closest_fish.vy)
        return
    else:  
        for blip in drone_radar_blips:
            if check_target(blip.id, drone, drone_radar_blips, my_scans, my_drones):
                drone.target = blip.id
                drone.target_type = get_type(blip.id, Creatures)
                drone.target_color = get_color(blip.id, Creatures)
                drone.target_x, drone.target_y = get_radar_hypothetical_position(drone.x, drone.y, blip.radar_location)
                return
    print_debug(f"Error: No target found")
    drone.target = None
    drone.target_type = None
    drone.target_color = None
    drone.target_x = None
    drone.target_y = None
    drone.target_vx = None
    drone.target_vy = None
    drone.target_distance = None
    drone.target_direction = None

# TODO: Implement emergency mode, Implement dodge mode, Implement return mode
# * Navigation System (main function)
# Handle drone movements
def NavigationSystem(drone: Drone, visible_fish: list[Fish], drone_radar_blips: list[RadarBlip], my_scans: list[int], my_drones: list[Drone]):
    choose_target(drone, visible_fish, drone_radar_blips, my_scans, my_drones)
    # Emergency mode
    if drone.emergency == True:
        drone.message = "Emergency"
        print_emergency(drone.message)
        return

    # Return according to scans
    if len(drone.scans) == 0:
        drone.returning = False
    if len(drone.scans) >= 4:
        drone.message = "Returning"
        drone.returning = True
        print_action(5000, 500, drone.light, drone.message)
        return

    # Targeting
    if drone.target != None and drone.returning == False:
        drone.message = "Targeting"
        print_action(drone.target_x, drone.target_y, drone.light, drone.message)
        return
    
    # if no target found return scans
    if drone.target == None:
        drone.message = "Nothing to scan"
        print_action(5000, 500, 0, drone.message)
        return

# ? ###############################################################################
# ? ################################## Prints #####################################
# ? ###############################################################################

# * Print debug message
# @params: message
def print_debug(message):
    print(f"{message}", file=sys.stderr, flush=True)

def print_action(target_x, target_y, light, message):
    print(f"MOVE {target_x} {target_y} {light} {message}")

def print_emergency(message):
    print(f"WAIT 0 {message}")

# ? ###############################################################################
# ? #################################### MAIN #####################################
# ? ###############################################################################
global GameInfos
GameInfos = Game(200, 10000, 10000)

global Creatures
Creatures = []

creature_count = int(input())
for i in range(creature_count):
    creature_id, color, _type = [int(j) for j in input().split()]
    # register creatures
    Creatures.append(Creature(creature_id, color, _type))

# game loop
while True:
    my_scans: List[int] = []
    foe_scans: List[int] = []
    drone_by_id: Dict[int, Drone] = {}
    my_drones: List[Drone] = []
    foe_drones: List[Drone] = []
    visible_fish: List[Fish] = []
    my_radar_blips: Dict[int, List[RadarBlip]] = {}

    my_score = int(input())
    foe_score = int(input())

    my_scan_count = int(input())
    for _ in range(my_scan_count):
        fish_id = int(input())
        #
        my_scans.append(fish_id)

    foe_scan_count = int(input())
    for _ in range(foe_scan_count):
        fish_id = int(input())
        #
        foe_scans.append(fish_id)

    my_drone_count = int(input())
    for _ in range(my_drone_count):
        drone_id, drone_x, drone_y, dead, battery = map(int, input().split())
        #
        drone = Drone(drone_id, drone_x, drone_y, dead, battery)
        drone_by_id[drone_id] = drone
        my_drones.append(drone)
        my_radar_blips[drone_id] = []

    foe_drone_count = int(input())
    for _ in range(foe_drone_count):
        drone_id, drone_x, drone_y, dead, battery = map(int, input().split())
        # 
        drone = Drone(drone_id, drone_x, drone_y, dead, battery)
        drone_by_id[drone_id] = drone
        foe_drones.append(drone)
    
    drone_scan_count = int(input())
    for _ in range(drone_scan_count):
        drone_id, fish_id = map(int, input().split())
        drone_by_id[drone_id].scans.append(fish_id)

    visible_fish_count = int(input())
    for _ in range(visible_fish_count):
        fish_id, fish_x, fish_y, fish_vx, fish_vy = map(int, input().split())
        #
        type = get_type(fish_id, Creatures)
        color = get_color(fish_id, Creatures)
        visible_fish.append(Fish(fish_id, fish_x, fish_y, fish_vx, fish_vy, color, type))

    my_radar_blip_count = int(input())
    for _ in range(my_radar_blip_count):
        drone_id, fish_id, dir = input().split()
        drone_id = int(drone_id)
        fish_id = int(fish_id)
        my_radar_blips[drone_id].append(RadarBlip(fish_id, dir))

    # Debug
    print(f"Scans:{my_scans} Visible fish:{visible_fish_count}", file=sys.stderr, flush=True)

    for drone in my_drones:
        
        # TODO: Implement emergency mode, Implement dodge mode, Implement return mode
        NavigationSystem(drone, visible_fish, my_radar_blips[drone.drone_id], my_scans, my_drones)
        # Debug
        print(f"Drone:{drone.drone_id} Scans:{drone.scans} Target:{drone.target} {drone.target_type} {drone.target_color} Target coord:{drone.target_x},{drone.target_y} target dir:{drone.target_vx},{drone.target_vy} dist:{drone.target_distance} dir: {drone.target_direction}", file=sys.stderr, flush=True)


""" Context and Rules of the Game:

GoalWin more points than your opponent by scanning the most fish.

To protect marine life, it is crucial to understand it. Explore the ocean floor using your drones to scan as many fish as possible to better understand them!

 	Rules
The game is played turn by turn. Each turn, each player gives an action for their drones to perform.

The Map
The map is a square of 10,000 units on each side. Length units will be denoted as "u" in the rest of the statement. The coordinate (0, 0) is located at the top left corner of the map.

Drones
Each player has two drones to explore the ocean floor and scan the fish. Each turn, the player can decide to move their drone in a direction or not activate its motors.

 
Your drone continuously emits light around it. If a fish is within this light radius, it is automatically scanned. You can increase the power of your light (and thus your scan radius), but this will drain your battery.

In order to save your scans and score points, you will need to resurface with your drone.

Fish
On the map, different fish are present. Each fish has a specific type and color. In addition to the points earned if you scan a fish and bring the scan back to the surface, bonuses will be awarded if you scan all the fish of the same type or same color, or if you are the first to do so.


Each fish moves within a habitat zone, depending on its type. Only fish within the light radius of one of your drones will be visible to you.

Depth Monsters
Depth monsters lurk! If they are blinded by the lights of a passing drone, they will start chasing it.


Unit Details
Drones
Drones move towards the given point, with a maximum distance per turn of 600u. If the motors are not activated in a turn, the drone will sink by 300u.

At the end of the turn, fish within a radius of 800u will be automatically scanned.

If you have increased the power of your light, this radius becomes 2000u, but the battery drains by 5 points. If the powerful light is not activated, the battery recharges by 1. The battery has a capacity of 30 and is fully charged at the beginning of the game.

If the drone is near the surface (y ≤ 500u), the scans will be automatically saved, and points will be awarded.

Radar
To better navigate the dark depths, drones are equipped with radars. For each creature (fish or monster) in the game zone, the radar will indicate:

TL: if the entity is somewhere top left of the drone.
TR: if the entity is somewhere top right of the drone.
BR: if the entity is somewhere bottom right of the drone.
BL: if the entity is somewhere bottom left of the drone.

Note: If the entity shares the same x-coordinate as the drone, it will be considered as being on the left. If the entity shares the same y-coordinate as the drone, it will be considered as being on the top.

Fish
Fish move 200u each turn, in a randomly chosen direction at the beginning of the game. Each fish moves within a habitat zone based on its type. If it reaches the edge of its habitat zone, it will rebound off the edge.

Fish	type	Y min	Y max
   	0	2500	5000
   	1	5000	7500
   	2	7500	10000
If a fish comes within 600u of another, it will begin to swim in the opposite direction to the nearest fish.

If a drone has its motors activated within a distance of less than 1400u, the fish will enter “frightened” mode in the next turn: in this mode, the fish will start swimming in the direction opposite to the nearest drone at a speed of 400u per turn. While frightened, the fish cannot exit its habitat on the y-coordinate (it will stay at that y-coordinate without bouncing), but if its x-coordinate becomes negative or greater than 9999, it will permanently leave the map and cannot be scanned anymore.


Monsters
If a monster is within a radius of 500u from a drone during a turn (so not necessarily at the end of the turn), the drone will enter “emergency” mode. In this mode, all unsaved scans will be lost. The drone will activate its buoys and start ascending at a speed of 300u per turn. Until the drone reaches the surface (y=0), the drone will continue to ascend, and actions will be ignored


Monsters are detectable a bit farther than your light radius (300u more than your light).

Monsters start the game with a zero speed. If a monster is within the light radius of a drone at the end of a turn, it enters “aggressive” mode and will dash in the direction of the nearest drone in the next turn at a speed of 540u.

If it is no longer within a light radius, it will continue swimming in that direction at a speed of 270u. During this non-aggressive swim, the monster will change direction if:

it is at y = 2500u or at the lateral edges of the map, the limit of its habitat that it can never cross.
it is within 600u of another monster, in which case it will go in the opposite direction of the nearest monster.
Creature	type	Y min	Y max	start Y min
	-1	2500	10000	5000
Score Details
Points are awarded for each scan depending on the type of scanned fish. Being the first to save a scan or a combination allows you to earn double the points.

Scan	Points	Points if first to save
Type 0 	1	2
Type 1 	2	4
Type 2 	3	6
All fish of one color   	3	6
All fish of one type    	4	8
At the end of the game, all unsaved scans are automatically saved, and associated points are awarded.

Victory Conditions
The game reaches 200 turns
A player has earned enough points that their opponent cannot catch up
Both players have saved the scans of all remaining fish on the map
Defeat Conditions
Your program does not return a valid command within the given time for each of your drones, including those in emergency mode.

🐞 Debugging Tips
Hover over an entity to see more information about it.
Add text at the end of an instruction to display that text above your drone.
Click on the gear icon to display additional visual options.
Use the keyboard to control actions: space for play/pause, arrows for step-by-step forward movement.
 	Technical Details
Physics Engine
Velocity vectors are rounded to the nearest integer.
Collision between drones and monsters can occur between two turns, calculated based on entity velocity vectors.
When selecting the closest entity to a fish or monster, in case of a tie, the average of the positions is taken.
Order of Actions
Turning on / off drone lights
Draining or recharging drone batteries
Movement of drones, fishes, monsters
Drone ↔ monster collision management
Updating monster targets
Fish scans
Saving drone scans at y ≤ 500
Emergency repairs for drones at y = 0
Updating fish speed
Updating monster speed according to their targets
 	Game Protocol
Initialization Input
First line: creatureCount an integer for the number of creatures in the game zone. Will always be 12.
Next creatureCount lines: 3 integers describing each creature:
creatureId for this creature's unique id.
color (0 to 3) and type (0 to 2). Monsters will be shown as -1 -1.
Input for One Game Turn
Next line: myScore for you current score.
Next line: foeScore for you opponent's score.

Next line: myScanCount for your amount of saved scans.
Next myScanCount lines: creatureId for each scan scored.

Next line: foeScanCount for your opponent's amount of saved scans.
Next foeScanCount lines: creatureId for each scan scored by your opponent.

Next line: myDroneCount for the number of drones you control.
Next myDroneCount lines:
droneId: this drone's unique id.
droneX and droneY: this drone's position.
emergency: 1 if the drone is in emergency mode, 0 otherwise.
battery: this drone's current battery level.
Next line: foeDroneCount for the number of drones your opponent controls.
Next foeDroneCount lines:
droneId: this drone's unique id.
droneX and droneY: this drone's position.
emergency: 1 if the drone is in emergency mode, 0 otherwise.
battery: this drone's current battery level.
Next line: droneScanCount for the amount of scans currently within a drone.
Next droneScanCount lines: droneId and creatureId describing which drone contains a scan of which fish.

Next line: visibleCreatureCount the number of creatures within the light radius of your drones.
Next visibleCreatureCount lines:
creatureId: this creature's unique id.
creatureX and creatureY: this creature's position.
creatureVx and creatureVy: this creature's current speed.
Next line: radarBlipCount.
Next radarBlipCount lines: Two integers droneId, creatureId and a string radar indicating the relative position between each creature and each one of your drones. radar can be:
TL: the creature is to the top-left of the drone.
TR: the creature is to the top-right of the drone.
BR: the creature is to the bottom-right of the drone.
BL: the creature is to the bottom-left of the drone.
Output
Next myDroneCount lines: one valid instruction for each of your drones, in the same order the drones were provided to you:
MOVE x y light: makes the drone move towards (x,y), engines on.
WAIT light. Switches engines off. The drone will sink but can still use light to scan nearby creatures.
Set light to 1 to activate the powerful light, 0 otherwise.
Constraints
13 ≤ creatureCount ≤ 20 depending on the number of monsters on the map.
myDroneCount = 2

Response time per turn ≤ 50ms
Response time for the first turn ≤ 1000ms
"""