import sys
import math

# Save humans, destroy zombies!
# 
#   Zombies move towards their targets.
#   Ash moves towards his target.
#   Any zombie within a 2000 unit range around Ash is destroyed.
#   Zombies eat any human they share coordinates with.

class Zombie:
    speed = 400
    range = 400

    def __init__(self, input_id:int, input_x, input_y, input_nx, input_ny):
        self.id = input_id
        self.x = input_x
        self.y = input_y
        self.nx = input_nx
        self.ny = input_ny
            
    def __str__(self):
        return f"Zombie {self.id}: {self.x}x, {self.y}y"
    

class Human:
    speed = 1000
    range = 2000
    closest_zombie : Zombie
    salvageable : bool = False
    salvageability_cost : float = 0
    closest_zombie_cost : float = 0

    def __init__(self, input_id: int = 0, input_x: int = 0, input_y: int = 0):
        self.id = input_id 
        self.x = input_x 
        self.y = input_y
    
    def __str__(self):
        return f"Human {self.id}: {self.x}x, {self.y}y {self.closest_zombie_cost} cost"
    
    def move_cost(self, source_x, source_y, target_x, target_y, method='euclidean'):
        """Calculate distance between two points using different methods
        Args:
            source_x, source_y: Starting coordinates
            target_x, target_y: Target coordinates
            method: Distance calculation method ('manhattan', 'euclidean', 'chebyshev')
        Returns:
            float: Distance between points
        """
        if method == 'manhattan':
            # Sum of absolute differences - good for grid movement
            return abs(source_x - target_x) + abs(source_y - target_y)
        elif method == 'chebyshev':
            # Maximum of absolute differences - good for 8-directional movement
            return max(abs(source_x - target_x), abs(source_y - target_y))
        else:  # euclidean
            # Straight line distance - good for free movement
            return math.sqrt((source_x - target_x) ** 2 + (source_y - target_y) ** 2) 

    def set_closest_zombie(self, zombie_list: list[Zombie]):
        closest_zombie : Zombie = None
        for zombie in zombie_list:
            if closest_zombie == None:
                closest_zombie = zombie
            if self.move_cost(human.x, human.y, zombie.x, zombie.y) < self.move_cost(human.x, human.y, closest_zombie.x, closest_zombie.y):
                closest_zombie = zombie
        self.closest_zombie = closest_zombie

    def get_salvageable_human(self, human_list: list['Human'], zombie_list: list[Zombie]) -> list['Human'] :
        # Define closest zombie for each human
        for human in human_list:
            closest_zombie : Zombie = None
            # print(human, file=sys.stderr, flush=True)
            for zombie in zombie_list:
                if closest_zombie == None:
                    closest_zombie = zombie
                if self.move_cost(human.x, human.y, zombie.x, zombie.y) < self.move_cost(human.x, human.y, closest_zombie.x, closest_zombie.y):
                    closest_zombie = zombie
            human.closest_zombie = closest_zombie
            # print(human.closest_zombie, file=sys.stderr, flush=True)

        # find which humans are salvageable
        # print(f"=========== Salvageable Calculations ==========", file=sys.stderr, flush=True)
        humans_salvageable : list['Human'] = []
        for human in human_list:
            zombie_move_cost = self.move_cost(human.x, human.y, human.closest_zombie.x, human.closest_zombie.y)
            ash_move_cost = self.move_cost(human.x, human.y, self.x, self.y)
            zombie_move_cost = (zombie_move_cost / Zombie.speed) - Zombie.range / Zombie.speed
            ash_move_cost = (ash_move_cost / Human.speed) - Human.range / Human.speed
            # print(f"Zombie {human.closest_zombie.id}: {zombie_move_cost} cost", file=sys.stderr, flush=True)
            # print(f"Ash : {ash_move_cost} cost", file=sys.stderr, flush=True)
            human.salvageability_cost = ash_move_cost
            human.closest_zombie_cost = zombie_move_cost
            if (zombie_move_cost >= ash_move_cost):
                humans_salvageable.append(human)
                print(f"Salvageable: {human}", file=sys.stderr, flush=True)

        return humans_salvageable

    
    def path_finder(self, human_list: list['Human'], zombie_list: list[Zombie]):
        humans_salvageable : list['Human'] = []
        humans_salvageable = self.get_salvageable_human(human_list, zombie_list)

        to_save : Human = None
        max_cost = math.inf
        for human in humans_salvageable:
            if human.closest_zombie_cost < max_cost:
                max_cost = human.closest_zombie_cost
                to_save = human
        
        self.set_closest_zombie(zombie_list)

        if to_save and to_save.closest_zombie_cost < 13:
            print(to_save.x, to_save.y)
        elif to_save == None:
            print(human_list[0].x, human_list[0].y)
        else:
            print(self.closest_zombie.x, self.closest_zombie.y)
        pass

class Map():
    width = 16000
    height = 9000
    top_left = (0, 0)

    human_count = 0
    human_list : list[Human] = []
    zombie_count = 0
    zombie_list : list[Zombie] = []

Zone = Map()
Ash = Human()

# game loop
while True:
    # Ash coord
    x, y = [int(i) for i in input().split()]
    Ash.x = x
    Ash.y = y
    # human count
    human_count = int(input())
    Zone.human_count = human_count
    # humans coords
    Zone.human_list.clear()
    for i in range(human_count):
        human_id, human_x, human_y = [int(j) for j in input().split()]
        human = Human(human_id, human_x, human_y)
        Zone.human_list.append(human)

    # Zomb count
    zombie_count = int(input())
    Zone.zombie_count = zombie_count
    # Zomb coords
    Zone.zombie_list.clear()
    for i in range(zombie_count):
        zombie_id, zombie_x, zombie_y, zombie_xnext, zombie_ynext = [int(j) for j in input().split()]
        zomb = Zombie(zombie_id, zombie_x, zombie_y, zombie_xnext, zombie_ynext)
        Zone.zombie_list.append(zomb)
        
    debug_zone = f'''Humans : {Zone.human_count} , Zombies: {Zone.zombie_count}
    Ash coord: {Ash.x}x, {Ash.y}y
    '''
    print(debug_zone, file=sys.stderr, flush=True)
    Ash.path_finder(Zone.human_list, Zone.zombie_list)


    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    # Your destination coordinates