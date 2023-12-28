from enum import Enum
from os import path
from re import T, escape
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

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

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
# ? ################################## Monsters ###################################
# ? ###############################################################################

# * Update monster list
# @params: monster, monster_list
def update_monsters(monster: Fish, monster_list: list[Fish]):
    for itermonster in monster_list:
        if monster.id == itermonster.id:
            itermonster.x = monster.x
            itermonster.y = monster.y
            itermonster.vx = monster.vx
            itermonster.vy = monster.vy
            return

# TODO: Implement foe drone death detection to determine monsters position
# * Update monster coord in list
# Update monster coord according to its speed, and last known position
# @params: monster_list
def update_monsters_coord(monster_list: list[Fish], visible_fish: list[Fish]):
    # Create a set of visible fish ids
    visible_fish_ids = set(fish.id for fish in visible_fish if fish.type == -1)
    for monster in monster_list:
        # If the monster's id is not in the set of visible fish ids, update its coordinates
        if monster.id not in visible_fish_ids:
            if monster.x + monster.vx <= 0 or monster.x + monster.vx >= GameInfos.max_x:
                monster.vx = -monster.vx
            if monster.y + monster.vy <= GameInfos.drone_safe_y or monster.y + monster.vy >= GameInfos.max_y:
                monster.vy = -monster.vy
            monster.x += (monster.vx)
            monster.y += (monster.vy)

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
def targeting_system(drone: Drone, visible_fish: list[Fish], drone_radar_blips: list[RadarBlip], my_scans: list[int], my_drones: list[Drone]):
    closest_fish = None
    min_distance = 1000000
    for fish in visible_fish:
        dist = get_distance(drone.x, drone.y, fish.x, fish.y)
        if dist < min_distance and check_target(fish.id, drone, drone_radar_blips, my_scans, my_drones) == True:
            min_distance = dist
            closest_fish = fish
    if closest_fish != None:
        drone.message = "Fish in visual"
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
                drone.message = "Fish in radar"
                drone.target = blip.id
                drone.target_type = get_type(blip.id, Creatures)
                drone.target_color = get_color(blip.id, Creatures)
                drone.target_x, drone.target_y = get_radar_hypothetical_position(drone.x, drone.y, blip.radar_location)
                drone.target_vx = None
                drone.target_vy = None
                drone.target_distance = get_distance(drone.x, drone.y, drone.target_x, drone.target_y)
                drone.target_direction = blip.radar_location
                return
    print_debug(f"Drone {drone.drone_id}: No target found")
    drone.target = None
    drone.target_type = None
    drone.target_color = None
    drone.target_x = None
    drone.target_y = None
    drone.target_vx = None
    drone.target_vy = None
    drone.target_distance = None
    drone.target_direction = None

# * Get next position of a drone
# if target is None, return current position
# @params: drone
# @return: x, y
def drone_next_position(drone: Drone) -> Point:
    if drone.target == None:
        return Point(drone.x, drone.y)
    else:
        distance = GameInfos.drone_speed
        # Step 2: Compute the differences
        dx = drone.target_x - drone.x
        dy = drone.target_y - drone.y
        # Step 3: Normalize the direction vector
        magnitude = math.sqrt(dx**2 + dy**2)
        unit_vector = (dx / magnitude, dy / magnitude)
        # Step 4: Compute the displacement
        displacement = (unit_vector[0] * distance, unit_vector[1] * distance)
        # Step 5: Add the displacement to A
        new_point = Point(drone.x + displacement[0], drone.y + displacement[1])
        return new_point

# * Find escape vector
# use pathfinding to find escape vector and avoid collision
# @params: drone, monster, monster_list
# @return: escape_vector(x, y)
def path_escape_vector(drone: Drone, closest_monster: Fish, monster_list: list[Fish], visible_list: list[Fish]) -> Point:
    escape_vector = Point(5000, 500)
    escape_priority = 0
    if len(drone.scans) > 0 and drone.y <= 2000:
        escape_vector.x = drone.x
        escape_vector.y = GameInfos.drone_scan_return
    if len(drone.scans) >= 5:
        if escape_priority == 0:
            escape_vector.x = drone.x
            escape_vector.y = drone.y - GameInfos.drone_speed
            if check_collision(drone, escape_vector, closest_monster, Monster_list) == False:
                return escape_vector
            else:
                escape_priority += 1
        if escape_priority == 1:
            escape_vector.x = drone.x - GameInfos.drone_speed
            escape_vector.y = drone.y - GameInfos.drone_speed
            if check_collision(drone, escape_vector, closest_monster, Monster_list) == False:
                return escape_vector
            else:
                escape_priority += 1
        if escape_priority == 2:
            escape_vector.x = drone.x + GameInfos.drone_speed
            escape_vector.y = drone.y - GameInfos.drone_speed
            if check_collision(drone, escape_vector, closest_monster, Monster_list) == False:
                return escape_vector
            else:
                escape_priority += 1
        if escape_priority == 3:
            escape_vector.x = drone.x - GameInfos.drone_speed
            escape_vector.y = drone.y
            if check_collision(drone, escape_vector, closest_monster, Monster_list) == False:
                return escape_vector
            else:
                escape_priority += 1
        if escape_priority == 4:
            escape_vector.x = drone.x + GameInfos.drone_speed
            escape_vector.y = drone.y
            if check_collision(drone, escape_vector, closest_monster, Monster_list) == False:
                return escape_vector
    escape_priority = 0
    if drone.target != None:
        if escape_priority == 0:
            if drone.target_direction == Directions.TL:
                escape_vector.x = drone.x - GameInfos.drone_speed
                escape_vector.y = drone.y - GameInfos.drone_speed
            elif drone.target_direction == Directions.TR:
                escape_vector.x = drone.x + GameInfos.drone_speed
                escape_vector.y = drone.y - GameInfos.drone_speed
            elif drone.target_direction == Directions.BL:
                escape_vector.x = drone.x - GameInfos.drone_speed
                escape_vector.y = drone.y + GameInfos.drone_speed
            elif drone.target_direction == Directions.BR:
                escape_vector.x = drone.x + GameInfos.drone_speed
                escape_vector.y = drone.y + GameInfos.drone_speed
            if check_collision(drone, escape_vector, closest_monster, monster_list) == False:
                return escape_vector
            else:
                escape_priority += 1
        if escape_priority == 1:
            if drone.target_direction == Directions.TL or drone.target_direction == Directions.BL:
                escape_vector.x = drone.x - GameInfos.drone_speed
                escape_vector.y = drone.y
            elif drone.target_direction == Directions.TR or drone.target_direction == Directions.BR:
                escape_vector.x = drone.x + GameInfos.drone_speed
                escape_vector.y = drone.y
            if check_collision(drone, escape_vector, closest_monster, monster_list) == False:
                return escape_vector
            else:
                escape_priority += 1
        if escape_priority == 2:
            if drone.target_direction == Directions.TL or drone.target_direction == Directions.TR:
                escape_vector.x = drone.x
                escape_vector.y = drone.y - GameInfos.drone_speed
            elif drone.target_direction == Directions.BL or drone.target_direction == Directions.BR:
                escape_vector.x = drone.x
                escape_vector.y = drone.y + GameInfos.drone_speed
            if check_collision(drone, escape_vector, closest_monster, monster_list) == False:
                return escape_vector
            else:
                escape_priority += 1
        if escape_priority == 3:
            print_debug(f"Drone {drone.drone_id} : No escape vector found")
    return escape_vector

# ! Not working
# * Vector intersection
# @params: drone_pos(x, y), drone_vector(vx, vy), monster_pos(x, y), monster_vector(vx, vy)
# @return: true if intersection, false if not
def vector_intersection(drone_pos: tuple[int, int], drone_vector: Point, monster_pos: tuple[int, int], monster_vector: tuple[int, int]) -> Point:
    A = Point(drone_pos[0], drone_pos[1])
    B = Point(drone_vector.x, drone_vector.y)
    C = Point(monster_pos[0], monster_pos[1])
    D = Point(monster_pos[0] + monster_vector[0], monster_pos[1] + monster_vector[1])

    # Line AB represented as a1x + b1y = c1
    a1 = B.y - A.y
    b1 = A.x - B.x
    c1 = a1*(A.x) + b1*(A.y)
 
    # Line CD represented as a2x + b2y = c2
    a2 = D.y - C.y
    b2 = C.x - D.x
    c2 = a2*(C.x) + b2*(C.y)
 
    determinant = a1*b2 - a2*b1
 
    if (determinant == 0):
        # The lines are parallel. This is simplified
        # by returning a pair of FLT_MAX
        return Point(10**9, 10**9)
    else:
        x = (b2*c1 - b1*c2)/determinant
        y = (a1*c2 - a2*c1)/determinant
    # Step 4: Return the intersection point
    return Point(x, y)

# * Check for collision between drone and monster
# @params: drone, drone_next_position, monster
# @return: True if collision, False if not
def check_collision(drone: Drone, drone_next_pos: Point, monster: Fish, Monster_list: list[Fish]) -> bool:
    for i in range(GameInfos.drone_speed, 0, -1):
        dist = get_distance(drone_next_pos.x - i/2, drone_next_pos.y - i/2, monster.x + monster.vx - min(GameInfos.monster_aggressive_speed, i)/2, monster.y + monster.vy - min(GameInfos.monster_aggressive_speed, i)/2)
        if dist <= GameInfos.monster_hitbox + GameInfos.drone_hitbox + 100:
            return True
    if get_distance(drone_next_pos.x, drone_next_pos.y, monster.x + monster.vx, monster.y + monster.vy) <= GameInfos.monster_hitbox + GameInfos.drone_hitbox + 100:
        return True
    for monsters in Monster_list:
        dist = get_distance(drone_next_pos.x, drone_next_pos.y, monsters.x + monsters.vx, monsters.y + monsters.vy)
        if dist <= GameInfos.monster_hitbox + GameInfos.drone_hitbox + 100:
            return True
    # vector_cross = vector_intersection((drone.x, drone.y), drone_next_pos, (monster.x, monster.y), (monster.vx, monster.vy))
    # if get_distance(drone_next_pos.x, drone_next_pos.y, vector_cross.x, vector_cross.y) <= GameInfos.monster_hitbox + GameInfos.drone_hitbox:
    #     return True
    return False

# * Avoid monsters
# Avoid monsters if they are in range, if not, return to normal mode
# @params: drone, visible_fish
def monster_avoid_system(drone: Drone, Monster_list: list[Fish], visible_fish: list[Fish]):
    next_drone_position = drone_next_position(drone)
    closest_monster = None
    min_distance = 1000000
    for monster in Monster_list:
        dist = get_distance(drone.x, drone.y, monster.x, monster.y)
        if dist < min_distance:
            min_distance = dist
            closest_monster = monster
    if closest_monster != None:
        if get_distance(drone.x, drone.y, closest_monster.x, closest_monster.y) <= GameInfos.monster_scan_range:
            drone.dodge = False
            drone.message = "Monster nearby"
        if get_distance(drone.x, drone.y, closest_monster.x, closest_monster.y) <= GameInfos.monster_aggressive_speed + GameInfos.monster_hitbox + GameInfos.drone_hitbox + GameInfos.drone_speed:
            drone.dodge = True
            drone.message = "Dodging"
            print_debug(f"Drone {drone.drone_id} : Monster {closest_monster.id} position {closest_monster.x},{closest_monster.y} dist {min_distance}")
            # if get_distance(next_drone_position.x, next_drone_position.y, closest_monster.x + closest_monster.vx, closest_monster.y + closest_monster.vy) <= GameInfos.monster_hitbox + GameInfos.drone_hitbox + 100:
            if check_collision(drone, next_drone_position, closest_monster, Monster_list) == True:
                escape_vector = path_escape_vector(drone, closest_monster, Monster_list, visible_fish)
                drone.target_x = escape_vector.x
                drone.target_y = escape_vector.y
                print_debug(f"Drone {drone.drone_id} : Monster {closest_monster.id} collision")
                drone.message = "Brace for impact"
            return
    drone.dodge = False
    drone.light = 1
    return

# TODO: Implement emergency mode, Implement dodge mode, Implement return mode
# * Navigation System (main function)
# Handle drone movements
def NavigationSystem(drone: Drone, visible_fish: list[Fish], drone_radar_blips: list[RadarBlip], my_scans: list[int], my_drones: list[Drone], Monster_list: list[Fish]):
    # Emergency mode
    if drone.emergency == True:
        drone.message = "Emergency"
        print_emergency(drone.message)
        return
    targeting_system(drone, visible_fish, drone_radar_blips, my_scans, my_drones)
    monster_avoid_system(drone, Monster_list, visible_fish)
    # Reset search
    if len(drone.scans) == 0:
        drone.returning = False
        drone.message = "Reset search"
    if drone.y <= GameInfos.drone_scan_return and drone.dodge == True:
        drone.dodge = False
    # Dodge
    if drone.dodge == True:
        if drone.target != None:
            print_action(drone.target_x, drone.target_y, drone.light, drone.message)
            return
        else:
            drone.target_x = drone.x
            drone.target_y = 500
            print_action(drone.target_x, drone.target_y, drone.light, drone.message)
        return
    # Return
    if drone.returning == True:
        drone.message = "Returning"
        print_action(5000, 500, drone.light, drone.message)
        return
    if len(drone.scans) >= 4 and drone.message == "Monster nearby":
        drone.message = "Monster - Return scans"
        drone.returning = True
        print_action(5000, 500, drone.light, drone.message)
        return

    # Targeting
    if drone.target != None and drone.returning == False:
        print_action(drone.target_x, drone.target_y, drone.light, drone.message)
        return
    
    # if no target found return scans
    if drone.target == None and len(my_scans) > 0:
        drone.message = "Nothing to scan"
        print_action(5000, 500, 0, drone.message)
        return
    # End of search
    if drone.target == None and drone.returning == False:
        drone.message = "End of search"
        print_action(5000, 500, drone.light, drone.message)
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

# Monsters
Monster_list: List[Fish] = []

creature_count = int(input())
for i in range(creature_count):
    creature_id, color, _type = [int(j) for j in input().split()]
    # register creatures
    Creatures.append(Creature(creature_id, color, _type))

for creature in Creatures:
    if creature.type == -1:
        Monster_list.append(Fish(creature.creature_id, 0, 0, 0, 0, creature.color, creature.type))

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
        if type == -1:
            monster = Fish(fish_id, fish_x, fish_y, fish_vx, fish_vy, color, type)
            update_monsters(monster, Monster_list)
    # Monster in radar update with last known position
    update_monsters_coord(Monster_list, visible_fish)
    # Debug
    for monster in Monster_list:
        print(f"Monster:{monster.id} position:{monster.x},{monster.y}", file=sys.stderr, flush=True)

    my_radar_blip_count = int(input())
    for _ in range(my_radar_blip_count):
        drone_id, fish_id, dir = input().split()
        drone_id = int(drone_id)
        fish_id = int(fish_id)
        my_radar_blips[drone_id].append(RadarBlip(fish_id, dir))

    # Debug
    print(f"Scans:{my_scans} Visible fish:{visible_fish_count}", file=sys.stderr, flush=True)
    for fish in visible_fish:
        print(f"Fish:{fish.id}", file=sys.stderr, flush=True)

    for drone in my_drones:

        # TODO: Implement emergency mode, Implement dodge mode, Implement return mode
        NavigationSystem(drone, visible_fish, my_radar_blips[drone.drone_id], my_scans, my_drones, Monster_list)
        # Debug
        print(f"Drone:{drone.drone_id} Scans:{drone.scans} Target:{drone.target} Target coord:{drone.target_x},{drone.target_y} target dir:{drone.target_vx},{drone.target_vy} dist:{drone.target_distance} dir: {drone.target_direction}", file=sys.stderr, flush=True)

"""
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