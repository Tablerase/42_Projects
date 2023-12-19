import sys
import math

# Classes
class Game:
    def __init__(self, max_turns, max_x, max_y):
        self.max_turns = max_turns
        self.max_x = max_x
        self.max_y = max_y
        self.turn = 0

class Player:
    def __init__(self, score, scan_count, drone_count):
        self.score = score
        self.scan_count = scan_count
        self.drone_count = drone_count
        self.drones_list = []
        self.fishes_list = []
        self.paths_list = []
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

# Functions
def move_to(x, y, light):
	print("MOVE {} {} {}".format(x, y, light))

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

# Initialization
# 10k u per axis | 200 turns
GameInfos = Game(200, 10000, 10000)

# Willy = Stardew Valley Fisherman
Willy = Player(0, 0, 1)
Willy.paths_list.append(Path(5000, 3000, False))
Willy.paths_list.append(Path(5000, 9200, False))

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
        print("Drone coord = {} {}", Willy.drones_list[0].drone_x, Willy.drones_list[0].drone_y, file=sys.stderr, flush=True)
        if Willy.drones_list[i].drone_x == Willy.paths_list[0].x and Willy.drones_list[i].drone_y == Willy.paths_list[0].y:
            Willy.paths_list[0].reached = True
            move_to(Willy.paths_list[1].x, Willy.paths_list[1].y, 1)
            Willy.paths_list[1].reached = False
        elif Willy.drones_list[i].drone_x == Willy.paths_list[1].x and Willy.drones_list[i].drone_y == Willy.paths_list[1].y:
            Willy.paths_list[1].reached = True
            move_to(Willy.paths_list[0].x, Willy.paths_list[0].y, 1)
            Willy.paths_list[0].reached = False
        elif Willy.paths_list[0].reached == False:
            move_to(Willy.paths_list[0].x, Willy.paths_list[0].y, 1)
        elif Willy.paths_list[1].reached == False:
            move_to(Willy.paths_list[1].x, Willy.paths_list[1].y, 1)
        
        else:
            print("Willy is lost", file=sys.stderr, flush=True)
             


# Context & Rules
""" Game Protocol
Initialization Input
First line: creatureCount an integer for the number of creatures in the game zone. Will always be 12.
Next creatureCount lines: 3 integers describing each creature:

    creatureId for this creature's unique id.
    color (0 to 3) and type (0 to 2).

Input for One Game Turn
myScore for you current score.
foeScore for you opponent's score.

myScanCount for your amount of scans
Next myScanCount lines: creatureId for each scan.

foeScanCount for your opponent's amount of scans.
Next foeScanCount lines: creatureId for each scan of your opponent.

For your drone:

    droneId: this drone's unique id.
    droneX and droneY: this drone's position.
    battery: this drone's current battery level. 

Next, for your opponent's drone:

    droneId: this drone's unique id.
    droneX and droneY: this drone's position.
    battery: this drone's current battery level. 


For every fish:

    creatureId: this creature's unique id.
    creatureX and creatureY: this creature's position.
    creatureVx and creatureVy: this creature's current speed.

The rest of the variables can be ignored and will be used in later leagues.
Output
One line: one valid instruction for your drone:

    MOVE x y light: makes the drone move towards (x,y), engines on.
    WAIT light. Switches engines off. The drone will sink but can still use light to scan nearby creatures.

Set light to 1 to activate the powerful light, 0 otherwise. 
"""