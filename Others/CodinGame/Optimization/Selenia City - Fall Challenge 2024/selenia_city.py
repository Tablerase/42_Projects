import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

"""
MagTub: bidirectionnal straight line between two buildings
    - permanent construction
    - tub cant cross each other
    - 5 tub max per building
    - each tube:
        - one pod at a time
        - travel time = 1 day (regarless of lenght)
        - tub carry capacity = 10 passengers
        - possibility to upgrade tubes so that several pod can be used at the same time
    
    - cost:
        'TUBE buildingId1 buildingId2'
        1 resource for each 0.1 km
        upgrade:
            'UPGRADE buildingId1 buildingId2'
            - increase pod capacity by 1
            - init cost * new capacity

Pod:
    - cost:
        'POD podId buildingId1 buildingId2 buildingId3 ...'
        if last and first building have the same id the pod will loop indefinetly
        - otherwise stop after reaching last stop
        - 1000 resources
        - path can be change for 250 ressources
    - delete:
        'DESTROY podId'
        - recover 750 resources by recycling the pod

Teleporter:
    - permanent construction
    - unlimited carry capacity
    - no travel time
    - path between two teleporter can cross
    - only one teleporter entrance per building
                       or exit

    - cost:
        'TELEPORT buildingIdEntrance buildingIdExit'
        5000 resources

Area:
    160 * 90
    max: 150 buildings
         1000 astronauts each month

Time:
    20 lunar months
    1 lunar month = 20 lunar day

Buildings:
    - Lunar modules:
        - permanently house astronauts
        - astronauts assign to specific lunar module type (20 types)
            - win point only if astronauts transport to corresponding module type
            - if distribution between same module type is good more points

    - Landing pads
        - Each month a rocket drop a group of astronauts in each pads
        - Pad :
            - Same type of astronauts at each landing (example: 5 tech, 10 obs)

Points:
    1 Astronaut:
        - Reach destination before end of month : max possibility = 100p
        - Speed : 50p
            - reduce by number of days to reach destination
        - Balancing : 50p
            - 50p - number of astronauts already reached the same module during this month
            - if neg = 0
    
==========================
City parsing

Resources (int):
    - total amount of resources
numTravelRoutes (list of 3 int for each element):
    - number of routes (teleporter and tube) present in city
    - 1st: building1, 2nd: building2, 3rd: transport capacity (0 in case of teleporter)
numPods (list of ints for each element):
    - pods available in the network
    - 1st: uuid of pod, 2nd: numStops in pod path
    - x'st : list of stops (building to reach in path order)
numNewBuildings (list of ints for each element):
    - number of buildings newly constructed
    - 1st: building type
        - 2nd: id, 3rd: x cord, 4st: y cord
            - 0 : lunar pad
            - other : lunar module type
                - 5st: amount of astronauts
                - x'st: list of astronauts with their types

=====================
Transport improvements

- TUBE
- UPGRADE
- TELEPORT
- POD
- DESTROY
- WAIT

Wait: 'WAIT' no action perform during turn
Multiple actions: use ; to separate the actions
                - example: 'TELEPORT 12 34;TUBE 23 45;UPGRADE 23 45'

====================
Astronauts
- moves autonomously toward their modules
- move toward nearest target module (without taking anything into account)

Movements order
- Teleporters:
    - any astronaut on entrance tp will take it if target distance of exit building less or equal to entrance building.
    - can take pod after teleport
- Pods allocations:
    - smallest id post has prio
- Astronauts alloc in pods:
    - astronaut smallest id/type has prio
- Pods :
    - astronaut disembark at each stop

=================
End of Lunar month 

All astronauts disappear
All pods returns to their starting point
Unused resources yield a 10% interest
"""

class Build:
    def __init__(self, x, y, id):
        self.x : int = x
        self.y : int = y
        self.id : int = id

class LandingPad(Build):
    def __init__(self):
        # dict of int key : type, to int value: amount of astronauts for this type
        astro_types : dict[int , int] = {}

class Module(Build):
    def __init__(self, x, y, id):
        super().__init__(x, y, id)
        module_type : int
        residents : int # astronauts shelterd in Lunar Modules

class Route:
    def __init__(self, build1, build2):
        self.build1 : int = build1
        self.build2 : int = build2

# MagTub: bidirectionnal straight line between two buildings
#     - permanent construction
#     - tub cant cross each other
#     - 5 tub max per building
#     - each tube:
#         - one pod at a time
#         - travel time = 1 day (regarless of lenght)
#         - tub carry capacity = 10 passengers
#         - possibility to upgrade tubes so that several pod can be used at the same time
    
#     - cost:
#         'TUBE buildingId1 buildingId2'
#         1 resource for each 0.1 km
#         upgrade:
#             'UPGRADE buildingId1 buildingId2'
#             - increase pod capacity by 1
#             - init cost * new capacity
class MagneticTub(Route):
    def __init__(self, build1, build2):
        super().__init__(build1, build2)
        self.pod : int
        self.travel_time = 1
        self.capacity = 10

# Teleporter:
#     - permanent construction
#     - unlimited carry capacity
#     - no travel time
#     - path between two teleporter can cross
#     - only one teleporter entrance per building
#                        or exit

#     - cost:
#         'TELEPORT buildingIdEntrance buildingIdExit'
#         5000 resources
class Teleporter(Route):
    def __init__(self, build1, build2):
        super().__init__(build1, build2)
        self.cost = 5000

# Pod:
#     - cost:
#         'POD podId buildingId1 buildingId2 buildingId3 ...'
#         if last and first building have the same id the pod will loop indefinetly
#         - otherwise stop after reaching last stop
#         - 1000 resources
#         - path can be change for 250 ressources
#     - delete:
#         'DESTROY podId'
#         - recover 750 resources by recycling the pod
class Pod:
    def __init__(self, id, *args : list[int]):
        self.id : int = id
        self.path = args
        self.cost = 1000
        self.change_cost = 250
        self.destroy_gain = 750

    def get_path(self):
        return f"POD {self.id} {self.path}"

    def destroy(self):
        return f"DESTROY {self.id}"

class Area:
    def __init__(self):
        self.x_min = 0
        self.x_max = 160
        self.y_min = 0
        self.y_max = 90
        self.builds_max = 150
        self.builds : int = 0
        self.astronauts_max = 1000
        self.astronauts : int

        self.month : int = 1

        self.resources : int = 0
        self.routes : set[tuple[int, int, int]] = set()
        self.mag_routes : list[MagneticTub] = []
        self.tp_routes : list[Teleporter] = []

    def __str__(self):
        return_string = "====={ Selenia City }======\n"
        return_string += f"{self.month}M {self.resources}$ {len(self.routes)} routes \
{len(self.mag_routes)}mag {len(self.tp_routes)}tp"
        return return_string

City = Area()

# game loop
day = 0
while True:
    resources = int(input())
    City.resources = resources

    num_travel_routes = int(input())
    for i in range(num_travel_routes):
        building_id_1, building_id_2, capacity = [int(j) for j in input().split()]
        new_tuple = (building_id_1, building_id_2, capacity)
        if capacity != 0:
            new_route = MagneticTub(building_id_1, building_id_2)
        else:
            new_route = Teleporter(building_id_1, building_id_2)
        if new_tuple not in City.routes:
            City.routes.add(new_tuple)
            if type(new_route) is Teleporter:
                City.tp_routes.append(new_route)
            elif type(new_route) is MagneticTub:
                City.mag_routes.append(new_route)

    num_pods = int(input())
    for i in range(num_pods):
        pod_properties = input()
    num_new_buildings = int(input())
    for i in range(num_new_buildings):
        building_properties = input()

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    print(City, file=sys.stderr, flush=True)
    # print(f"", file=sys.stderr, flush=True)


    # TUBE | UPGRADE | TELEPORT | POD | DESTROY | WAIT
    # print("TUBE 0 1;TUBE 0 2;POD 42 0 1 0 2 0 1 0 2")
    print("TUBE 0 1")
    # print("WAIT")


    City.month += 1
    # TODO Reset info for astronaut and pod pos