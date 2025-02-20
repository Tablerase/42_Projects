import sys
import math

############### Classes ###############
class Game:
    def __init__(self, max_turns, max_x, max_y):
        self.max_turns = max_turns
        self.max_x = max_x
        self.max_y = max_y
        # drone
        self.drone_autorange = 800
        self.drone_range_light = 2000
        self.drone_range_light_cost = 5
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
        self.turn = 0

class FishType:
    def __init__(self, type_id, min_y, max_y):
        self.type_id = type_id
        self.min_y = min_y
        self.max_y = max_y

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

class Creature:
	def __init__(self, creature_id, color, type):
		self.creature_id = creature_id
		self.color = color
		self._type = type

class Drone:
    def __init__(self, drone_id, drone_x, drone_y, emergency, battery):
        self.drone_id = drone_id
        self.drone_x = drone_x
        self.drone_y = drone_y
        self.emergency = emergency
        self.battery = battery

class Fish:
    def __init__(self, creature_id, creature_x, creature_y, creature_vx, creature_vy):
        self.creature_id = creature_id
        self.creature_x = creature_x
        self.creature_y = creature_y
        self.creature_vx = creature_vx
        self.creature_vy = creature_vy

# List
creatures = []
drones = []
fishes = []

################## Functions ##################
def move_to(x, y, light, battery):
	print("MOVE {} {} {} {}".format(x, y, light, battery))

def wait(light):
	print("WAIT {}".format(light))

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

def add_fish_to_list(creature_id, new_fish, fishes_list):
    if creature_id not in fishes_list:
        fishes_list.append(new_fish)

def add_or_update_drone(drone_id, drone_x, drone_y, emergency, battery, drones_list):
    found = False
    for drone in drones_list:
        if drone.drone_id == drone_id:
            drone.drone_x = drone_x
            drone.drone_y = drone_y
            drone.emergency = emergency
            drone.battery = battery
            found = True
            break
    if not found:
        drones_list.append(Drone(drone_id, drone_x, drone_y, emergency, battery))

# * Willy's pathing
# Cycle through the list of paths
# @params: drone, paths_list
def pathing(drone, paths_list):
    if drone.drone_x == paths_list[0].x and drone.drone_y == paths_list[0].y:
        paths_list[0].reached = True
        move_to(paths_list[1].x, paths_list[1].y, 1, drone.battery)
        paths_list[1].reached = False
    elif drone.drone_x == paths_list[1].x and drone.drone_y == paths_list[1].y:
        paths_list[1].reached = True
        move_to(paths_list[2].x, paths_list[2].y, 1, drone.battery)
        paths_list[2].reached = False
    elif drone.drone_x == paths_list[2].x and drone.drone_y == paths_list[2].y:
        paths_list[2].reached = True
        move_to(paths_list[0].x, paths_list[0].y, 1, drone.battery)
        paths_list[0].reached = False
    elif paths_list[0].reached == False:
        move_to(paths_list[0].x, paths_list[0].y, 1, drone.battery)
    elif paths_list[1].reached == False:
        move_to(paths_list[1].x, paths_list[1].y, 1, drone.battery)
    elif paths_list[2].reached == False:
        move_to(paths_list[2].x, paths_list[2].y, 1, drone.battery)
    else:
        print("Willy is lost", file=sys.stderr, flush=True)

######### Initialization #########
# 10k u per axis | 200 turns
GameInfos = Game(200, 10000, 10000)

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
    creatures.append(Creature(creature_id, color, _type))

# game loop
while True:
    my_score = int(input())
    Willy.score = my_score
	
    foe_score = int(input())

    my_scan_count = int(input())
    Willy.scan_count = my_scan_count

    for i in range(my_scan_count):
        creature_id = int(input())

    foe_scan_count = int(input())
    for i in range(foe_scan_count):
        creature_id = int(input())

    my_drone_count = int(input())
    for i in range(my_drone_count):
        drone_id, drone_x, drone_y, emergency, battery = [int(j) for j in input().split()]
        add_or_update_drone(drone_id, drone_x, drone_y, emergency, battery, Willy.drones_list)

    foe_drone_count = int(input())
    for i in range(foe_drone_count):
        drone_id, drone_x, drone_y, emergency, battery = [int(j) for j in input().split()]

    drone_scan_count = int(input())
    for i in range(drone_scan_count):
        drone_id, creature_id = [int(j) for j in input().split()]

    visible_creature_count = int(input())
    for i in range(visible_creature_count):
        creature_id, creature_x, creature_y, creature_vx, creature_vy = [int(j) for j in input().split()]
        # new_fish = Fish(creature_id, creature_x, creature_y, creature_vx, creature_vy)
        # add_fish_to_list(fishes, creature_id, new_fish)

    radar_blip_count = int(input())
    for i in range(radar_blip_count):
        inputs = input().split()
        drone_id = int(inputs[0])
        creature_id = int(inputs[1])
        radar = inputs[2]
    for i in range(my_drone_count):
        # Write an action using print
        # To debug: print("Debug messages...", file=sys.stderr, flush=True)
        # MOVE <x> <y> <light (1|0)> | WAIT <light (1|0)>
        print("Drone coord = {} {}", Willy.drones_list[i].drone_x, Willy.drones_list[i].drone_y, file=sys.stderr, flush=True)
        pathing(Willy.drones_list[i], Paths[i])


# Context & Rules
""" Wood 1
If a drone has its motors activated within a distance of less than 1400u, 
the fish will enter “frightened” mode in the next turn: in this mode, 
the fish will start swimming in the direction opposite to the nearest drone at a speed of 400u per turn. 
While frightened, the fish cannot exit its habitat on the y-coordinate (it will stay at that y-coordinate without bouncing), 
but if its x-coordinate becomes negative or greater than 9999, it will permanently leave the map and cannot be scanned anymore.


Next myDroneCount lines: one valid instruction for each of your drones, in the same order the drones were provided to you:

    MOVE x y light: makes the drone move towards (x,y), engines on.
    WAIT light. Switches engines off. The drone will sink but can still use light to scan nearby creatures.

Set light to 1 to activate the powerful light, 0 otherwise.
Constraints
creatureCount = 12 in this league
myDroneCount = 2
"""

""" Game Protocol - Wood 2
Goal
Win more points than your opponent by scanning the most fish.

To protect marine life, it is crucial to understand it. Explore the ocean floor using your drone to scan as many fish as possible to better understand them!
  Rules

The game is played turn by turn. Each turn, each player gives an action for their drone to perform.
The Map

The map is a square of 10,000 units on each side. Length units will be denoted as "u" in the rest of the statement. The coordinate (0, 0) is located at the top left corner of the map.
Drones

Each player has a drone to explore the ocean floor and scan the fish. Each turn, the player can decide to move their drone in a direction or not activate its motors.

Your drone continuously emits light around it. If a fish is within this light radius, it is automatically scanned. You can increase the power of your light (and thus your scan radius), but this will drain your battery.

In order to save your scans and score points, you will need to resurface with your drone.
Fish

On the map, different fish are present. Each fish has a specific type and color. In addition to the points earned if you scan a fish and bring the scan back to the surface, bonuses will be awarded if you scan all the fish of the same type or same color, or if you are the first to do so.

Each fish moves within a habitat zone, depending on its type. Only fish within the light radius of your drone will be visible to you.
Unit Detai

On the map, different fish are present. Each fish has a specific type and color. In addition to the points earned if you scan a fish and bring the scan back to the surface, bonuses will be awarded if you scan all the fish of the same type or same color, or if you are the first to do so.

Each fish moves within a habitat zone, depending on its type. Only fish within the light radius of your drone will be visible to you.
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
Score Details

Points are awarded for each scan depending on the type of scanned fish. Being the first to save a scan or a combination allows you to earn double the points.
Scan 	Points 	Points if first to save
Type 0 	1 	2
Type 1 	2 	4
Type 2 	3 	6
All fish of one color 	3 	6
All fish of one type 	4 	8

At the end of the game, all unsaved scans are automatically saved, and associated points are awarded.
"""