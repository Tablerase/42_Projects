from hmac import new
import sys
import math

############### Classes ###############
class Game:
    def __init__(self, max_turns, max_x, max_y):
        self.max_turns = max_turns
        self.max_x = max_x
        self.max_y = max_y
        self.turn = 0
        # drone
        self.drone_autorange = 800
        self.drone_range_light = 2000
        self.drone_range_light_cost = 5
        self.drone_optimal_light_init = 2000
        # fish
        self.fish_speed = 200
        self.fish_rebound = 600
        self.fish_frightened_speed = 400
        self.fish_frightened_range = 1400

        self.fish_escape_xmax = 9999
        self.fish_escape_xmin = 0

        self.fish_type_0 = FishType(0, 2500, 5000)
        self.fish_type_1 = FishType(1, 5000, 7500)
        self.fish_type_2 = FishType(2, 7500, 10000)
        self.fish_color = [0, 1, 2, 3]
        # monster
        self.monster_speed = 270
        self.monster_aggressive_speed = 540
        self.monster_range = 500
        self.monster_rebound = 600
        self.monster_scan_range = 2300
        self.monster = FishType(-1, 2500, 10000)
        self.monster_color = -1
        self.monster_spawn_y = 5000

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

class Player:
    def __init__(self, score, scan_count, drone_count):
        self.score = score
        self.scan_count = scan_count
        self.drone_count = drone_count
        self.drones_list = []
        self.fishes_list = []
        self.list_of_paths = []
    def add_fish_to_list(self, creature_id, new_fish):
        found = False
        for fish in self.fishes_list:
            if fish.creature_id == creature_id:
                found = True
                break
        if not found:
            self.fishes_list.append(new_fish)

class Path:
    def __init__(self, x, y, bool):
        self.x = x
        self.y = y
        self.reached = bool

class Drone:
    def __init__(self, drone_id, drone_x, drone_y, emergency, battery):
        self.drone_id = drone_id
        self.drone_x = drone_x
        self.drone_y = drone_y
        self.emergency = emergency
        self.battery = battery
        self.scans_list = []
        self.radar_list = []

class RadarInfos:
    def __init__(self, creature_id, radar_location):
        self.creature_id = creature_id
        self.radar_location = radar_location

class Fish:
    def __init__(self, creature_id, creature_x, creature_y, creature_vx, creature_vy, color, type):
        self.creature_id = creature_id
        self.color = color
        self.type = type
        self.creature_x = creature_x
        self.creature_y = creature_y
        self.creature_vx = creature_vx
        self.creature_vy = creature_vy

################## Radar ##################

def add_or_update_radar(new_radar, drone):
    found = False
    for radar in drone.radar_list:
        if radar.creature_id == new_radar.creature_id:
            radar.radar_location = new_radar.radar_location
            found = True
            break
    if not found:
        drone.radar_list.append(new_radar)

################## Drone ##################

def add_or_update_drone(drone_id, drone_x, drone_y, emergency, battery, drones_list):
    found = False
    for drone in drones_list:
        if drone.drone_id == drone_id:
            drone.drone_x = drone_x
            drone.drone_y = drone_y
            drone.emergency = emergency
            if drone.emergency == 1:
                del drone.scans_list[:]
            drone.battery = battery
            found = True
            break
    if not found:
        drones_list.append(Drone(drone_id, drone_x, drone_y, emergency, battery))

################## Fish ##################

def add_or_update_fish(new_fish, fishes_list):
    found = False
    for fish in fishes_list:
        if new_fish.creature_id == fish.creature_id:
            fish.creature_x = new_fish.creature_x
            fish.creature_y = new_fish.creature_y
            fish.creature_vx = new_fish.creature_vx
            fish.creature_vy = new_fish.creature_vy
            found = True
            break
    if not found:
        fishes_list.append(new_fish)

def get_type(creature_id, creature_list):
    for creature in creature_list:
        if creature.creature_id == creature_id:
            return creature.type

def get_color(creature_id, creature_list):
    for creature in creature_list:
        if creature.creature_id == creature_id:
            return creature.color

def get_position(creature_id, creature_list):
    for creature in creature_list:
        if creature.creature_id == creature_id:
            return creature.creature_x, creature.creature_y

################## Functions ##################
def move_to(drone, x, y, light, battery):
    if drone.drone_y >= GameInfos.drone_optimal_light_init and drone.drone_y <= 4200:
        print("MOVE {} {} {} {}".format(x, y, 1, battery))
    else:
	    print("MOVE {} {} {} {}".format(x, y, 0, battery))

def wait(light):
	print("WAIT {}".format(light))
     
def debug(text):
    print("WAIT {}".format(1, text))
    print("DEBUG" + text, file=sys.stderr, flush=True)

def distance(x1, y1, x2, y2):
	return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

def get_closest_fish(drone, fishes):
	closest_fish = None
	min_distance = 1000000
	for fish in fishes:
		dist = distance(drone.drone_x, drone.drone_y, fish.creature_x, fish.creature_y)
		if dist < min_distance:
			min_distance = dist
			closest_fish = fish
	return closest_fish

def add_fish_to_list(new_fish, fishes_list):
    if new_fish.creature_id not in fishes_list:
        fishes_list.append(new_fish)



# * Willy's pathing
# Cycle through the list of paths
# @params: drone, paths_list
def pathing(drone, paths_list):
    if drone.drone_x == paths_list[0].x and drone.drone_y == paths_list[0].y:
        paths_list[0].reached = True
        move_to(drone, paths_list[1].x, paths_list[1].y, 1, drone.battery)
        paths_list[1].reached = False
    elif drone.drone_x == paths_list[1].x and drone.drone_y == paths_list[1].y:
        paths_list[1].reached = True
        move_to(drone, paths_list[2].x, paths_list[2].y, 1, drone.battery)
        paths_list[2].reached = False
    elif drone.drone_x == paths_list[2].x and drone.drone_y == paths_list[2].y:
        paths_list[2].reached = True
        move_to(drone, paths_list[0].x, paths_list[0].y, 1, drone.battery)
        paths_list[0].reached = False
    elif paths_list[0].reached == False:
        move_to(drone, paths_list[0].x, paths_list[0].y, 1, drone.battery)
    elif paths_list[1].reached == False:
        move_to(drone, paths_list[1].x, paths_list[1].y, 1, drone.battery)
    elif paths_list[2].reached == False:
        move_to(drone, paths_list[2].x, paths_list[2].y, 1, drone.battery)
    else:
        debug("Willy is lost")

###################### Navigation System ######################
# * Willy's navigation system

# def NavigationSystem(drone, radar_fish, visible_fish):
#     ...

######### Initialization #########
# 10k u per axis | 200 turns
GameInfos = Game(200, 10000, 10000)
Creatures = []
Visible_Creatures = []

# Willy = Stardew Valley Fisherman
Willy = Player(0, 0, 1)
# Paths
Path1 = []
Path1.append(Path(2000, 3000, False))
Path1.append(Path(2000, 9200, False))
Path1.append(Path(2000, 500, False))
Path2 = []
Path2.append(Path(8000, 3000, False))
Path2.append(Path(8000, 9200, False))
Path2.append(Path(8000, 500, False))
Paths = [Path1, Path2]

# Score points by scanning valuable fish faster than your opponent.

creature_count = int(input())
for i in range(creature_count):
    creature_id, color, _type = [int(j) for j in input().split()]
    Creatures.append(Creature(creature_id, color, _type))

# game loop
while True:
    # Scores
    my_score = int(input())
    Willy.score = my_score
	
    foe_score = int(input())
    # Scans
    my_scan_count = int(input())
    Willy.scan_count = my_scan_count
    for i in range(my_scan_count):
        creature_id = int(input())

    foe_scan_count = int(input())
    for i in range(foe_scan_count):
        creature_id = int(input())
    # Drones
    my_drone_count = int(input())
    for i in range(my_drone_count):
        drone_id, drone_x, drone_y, emergency, battery = [int(j) for j in input().split()]
        # recover data
        add_or_update_drone(drone_id, drone_x, drone_y, emergency, battery, Willy.drones_list)

    foe_drone_count = int(input())
    for i in range(foe_drone_count):
        drone_id, drone_x, drone_y, emergency, battery = [int(j) for j in input().split()]

    drone_scan_count = int(input())
    for i in range(drone_scan_count):
        drone_id, creature_id = [int(j) for j in input().split()]
        # recover data
        for drone in Willy.drones_list:
             if drone_id == drone.drone_id:
                for fish in Visible_Creatures:
                    if fish.creature_id == creature_id:
                        add_or_update_fish(fish, drone.scans_list)
                        break

    visible_creature_count = int(input())
    for i in range(visible_creature_count):
        creature_id, creature_x, creature_y, creature_vx, creature_vy = [int(j) for j in input().split()]
        # recover data
        for creature in Creatures:
            if creature.creature_id == creature_id:
                new_fish = Fish(creature_id, creature_x, creature_y, creature_vx, creature_vy, creature.color, creature.type)
                add_fish_to_list(new_fish, Visible_Creatures)
                break

    # Radar
    radar_blip_count = int(input())
    for i in range(radar_blip_count):
        inputs = input().split()
        drone_id = int(inputs[0])
        creature_id = int(inputs[1])
        radar = inputs[2]
        # recover data
        new_radar = RadarInfos(creature_id, radar)
        for drone in Willy.drones_list:
            if drone.drone_id == drone_id:
                add_or_update_radar(new_radar, drone)
                break

    # Drone count / action per drone loop
        # Write an action using print
        # To debug: print("Debug messages...", file=sys.stderr, flush=True)
        # MOVE <x> <y> <light (1|0)> | WAIT <light (1|0)>
    for i in range(my_drone_count):    
        print("Drone coord = {} {}".format(Willy.drones_list[i].drone_x, Willy.drones_list[i].drone_y), file=sys.stderr, flush=True)
        pathing(Willy.drones_list[i], Paths[i])
        for scans in Willy.drones_list[i].scans_list:
            print("Drone {} has scanned fish of type {}".format(Willy.drones_list[i].drone_id, scans.type), file=sys.stderr, flush=True)
        for radar in Willy.drones_list[i].radar_list:
            print("Drone {} has detected fish {} of type {} and coord:{}".format(Willy.drones_list[i].drone_id, radar.radar_location, get_type(radar.creature_id, Creatures), get_position(radar.creature_id, Visible_Creatures)), file=sys.stderr, flush=True)
        # NavigationSystem()


# Context & Rules
"""
 Goal
Win more points than your opponent by scanning the most fish.

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
Fish 	type 	Y min 	Y max
	0 	2500 	5000
	1 	5000 	7500
	2 	7500 	10000

If a fish comes within 600u of another, it will begin to swim in the opposite direction to the nearest fish.

If a drone has its motors activated within a distance of less than 1400u, the fish will enter “frightened” mode in the next turn: in this mode, the fish will start swimming in the direction opposite to the nearest drone at a speed of 400u per turn. While frightened, the fish cannot exit its habitat on the y-coordinate (it will stay at that y-coordinate without bouncing), but if its x-coordinate becomes negative or greater than 9999, it will permanently leave the map and cannot be scanned anymore.
Monsters

If a monster is within a radius of 500u from a drone during a turn (so not necessarily at the end of the turn), the drone will enter “emergency” mode. In this mode, all unsaved scans will be lost. The drone will activate its buoys and start ascending at a speed of 300u per turn. Until the drone reaches the surface (y=0), the drone will continue to ascend, and actions will be ignored

Monsters are detectable a bit farther than your light radius (300u more than your light).

Monsters start the game with a zero speed. If a monster is within the light radius of a drone at the end of a turn, it enters “aggressive” mode and will dash in the direction of the nearest drone in the next turn at a speed of 540u.

If it is no longer within a light radius, it will continue swimming in that direction at a speed of 270u. During this non-aggressive swim, the monster will change direction if:

    it is at y = 2500u or at the lateral edges of the map, the limit of its habitat that it can never cross.
    it is within 600u of another monster, in which case it will go in the opposite direction of the nearest monster.

Creature 	type 	Y min 	Y max 	start Y min
	-1 	2500 	10000 	5000
Score Details

Points are awarded for each scan depending on the type of scanned fish. Being the first to save a scan or a combination allows you to earn double the points.
Scan 	Points 	Points if first to save
Type 0 	1 	2
Type 1 	2 	4
Type 2 	3 	6
All fish of one color 	3 	6
All fish of one type 	4 	8

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