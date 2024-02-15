# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    the_descent.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 12:34:47 by rcutte            #+#    #+#              #
#    Updated: 2024/02/11 13:21:38 by rcutte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from ast import List
import sys
import math

# The while loop represents the game.
# Each iteration represents a turn of the game
# where you are given inputs (the heights of the mountains)
# and where you have to print an output (the index of the mountain to fire on)
# The inputs you are given are automatically updated according to your last actions.

class Mountains:
    def __init__(self, height):
        self.height = height

    def __str__(self):
        return "Mountain height: " + str(self.height)


def get_hightest_mountain(mountains: list) -> int:
    highest = 0
    for mountain in mountains:
        if mountain.height > highest:
            highest = mountain.height
    return highest

def get_index(mountains: list, target: int) -> int:
    for i in range(8):
        if mountains[i].height == target:
            return i
    return -1

# game loop
while True:
    mountains = []
    for i in range(8):
        mountain_h = int(input())  # represents the height of one mountain.
        mountains.append(Mountains(mountain_h))

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)
    for mountain in mountains:
        print(mountain, file=sys.stderr, flush=True)

    # The index of the mountain to fire on.
    target = get_hightest_mountain(mountains)
    print("Target height: " + str(target), file=sys.stderr, flush=True)

    index = get_index(mountains, target)
    if index == -1:
        print("Error: Index not found", file=sys.stderr, flush=True)
    print("Index of target: " + str(index), file=sys.stderr, flush=True)
    print(index)
