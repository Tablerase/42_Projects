# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    power_of_thor.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 15:02:36 by rcutte            #+#    #+#              #
#    Updated: 2024/02/11 16:30:45 by rcutte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import enum
import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
# ---
# Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.

# light_x: the X position of the light of power
# light_y: the Y position of the light of power
# initial_tx: Thor's starting X position
# initial_ty: Thor's starting Y position
light_x, light_y, initial_tx, initial_ty = [int(i) for i in input().split()]

class Lightning:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Direction(enum.Enum):
        north = "N"
        north_west = "NW"
        north_east = "NE"
        south = "S"
        south_west = "SW"
        south_east = "SE"
        east = "E"
        west = "W"

class Thor:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.speed = 1

    def go_to_lightning(self, target: Lightning) -> Direction:
        if self.y == target.y:
            if self.x < target.x:
                return Direction.east
            else:
                return Direction.west
        elif self.y < target.y:
            if self.x == target.x:
                return Direction.south
            elif self.x < target.x:
                return Direction.south_east
            else:
                return Direction.south_west
        else:
            if self.x == target.x:
                return Direction.north
            elif self.x < target.x:
                return Direction.north_east
            else:
                return Direction.north_west

    def update_position(self, move: Direction):
        if move == Direction.south:
            self.y = self.y - 1
        elif move == Direction.north:
            self.y = self.y + 1
        elif move == Direction.east:
            self.x = self.x + 1
        elif move == Direction.west:
            self.x = self.x - 1
        elif move == Direction.north_east:
            self.x = self.x + 1
            self.y = self.y - 1
        elif move == Direction.north_west:
            self.x = self.x - 1
            self.y = self.y - 1
        elif move == Direction.south_east:
            self.x = self.x + 1
            self.y = self.y + 1
        elif move == Direction.south_west:
            self.x = self.x + 1
            self.y = self.y + 1
        else:
            print("No direction found", file=sys.stderr, flush=True)
    
    def __str__(self) -> str:
        return "Position: " + str(self.x) + "x," + str(self.y) + "y"

lightning = Lightning(light_x, light_y)
thor = Thor(initial_tx, initial_ty)
# game loop
while True:
    remaining_turns = int(input())  # The remaining amount of turns Thor can move. Do not remove this line.

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)


    # A single line providing the move to be made: N NE E SE S SW W or NW
    print(thor, file=sys.stderr, flush=True)

    direction = thor.go_to_lightning(lightning)
    print("Direction: " + str(direction), file=sys.stderr, flush=True)
    print(direction.value)

    thor.update_position(direction)
    print(thor, file=sys.stderr, flush=True)

# Infos:
"""
  <===========> x

^
|       N
|       |
| W ----+---- E
|       |
|       S
v

y

"""
# Map is 40x18
# top left is 0,0 and bottom right is 39,17