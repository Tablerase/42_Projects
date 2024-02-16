# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mars_lander_ep2.py                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 21:02:41 by rcutte            #+#    #+#              #
#    Updated: 2024/02/16 23:22:02 by rcutte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import math

class mars:
    def __init__(self, surface_n):
        self.surface_n = surface_n
        self.map = []

        self.gravity = 3.711
        self.landing_size = 1000
        self.area = 7000
        self.high = 3000

        self.landing_area = {
            "start": 0,
            "end": 0,
            "height": 0
        }
    
    def landing_zone(self):
        min_point = self.map[0]
        for point in self.map:
            if point[1] == min_point[1] and point[0] != min_point[0]:
                self.landing_area["start"] = min_point[0]
                self.landing_area["end"] = point[0]
                self.landing_area["height"] = point[1]
                break
            else:
                min_point = point
    
    def __str__(self):
        return f"Landing_Area: {self.landing_area}, Surface_N: {self.surface_n}, Map: {self.map}"

Mars = mars(0)

surface_n = int(input())  # the number of points used to draw the surface of Mars.
for i in range(surface_n):
    # land_x: X coordinate of a surface point. (0 to 6999)
    # land_y: Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
    land_x, land_y = [int(j) for j in input().split()]
    Mars.map.append((land_x, land_y))

Mars.surface_n = surface_n
Mars.landing_zone()

class ship:
    def __init__(self, x, y, h_speed, v_speed, fuel, rotate, power):
        self.x = x
        self.y = y
        self.h_speed = h_speed
        self.v_speed = v_speed
        self.fuel = fuel
        self.rotate = rotate
        self.power = power

        self.thrust_range = [0, 1, 2, 3, 4]
        self.landing_v_speed = 40
        self.landing_h_speed = 20
        self.landing_angle = 0
        self.fuel = 500

        self.rotate_range = [-90, 90]

    def update(self, x, y, h_speed, v_speed, fuel, rotate, power):
        self.x = x
        self.y = y
        self.h_speed = h_speed
        self.v_speed = v_speed
        self.fuel = fuel
        self.rotate = rotate
        self.power = power
    
    def nav(self) -> tuple[int, int]:
        if self.x < Mars.landing_area["start"]:
            if self.h_speed <= 40 and self.x < Mars.landing_area["start"] - 1000:
                return (-45, 3)
            elif self.v_speed > -30:
                return (0, 3)
            else:
                return (0, 4)
        elif self.x > Mars.landing_area["start"] - 500:
            if self.h_speed >= self.landing_h_speed:
                return (45, 4)
            elif self.v_speed <= -self.landing_v_speed:
                return (0, 4)
            else:
                return (0, 3)
        else:
            return (0, 3)

    def __str__(self):
        return f"X: {self.x}, Y: {self.y}, H_Speed: {self.h_speed}, V_Speed: {self.v_speed}, Fuel: {self.fuel}, Rotate: {self.rotate}, Power: {self.power}"

Lander = ship(0, 0, 0, 0, 0, 0, 0)

# game loop
while True:
    # h_speed: the horizontal speed (in m/s), can be negative.
    # v_speed: the vertical speed (in m/s), can be negative.
    # fuel: the quantity of remaining fuel in liters.
    # rotate: the rotation angle in degrees (-90 to 90).
    # power: the thrust power (0 to 4).
    x, y, h_speed, v_speed, fuel, rotate, power = [int(i) for i in input().split()]
    Lander.update(x, y, h_speed, v_speed, fuel, rotate, power)

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)
    print(Mars, file=sys.stderr, flush=True)
    print(Lander, file=sys.stderr, flush=True)

    # 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
    print(str(Lander.nav()[0]) + " " + str(Lander.nav()[1]))


''' Mars Lander - Episode 2 - Rules:
The Goal
The goal for your program is to safely land the "Mars Lander" shuttle, the landing ship which contains the Opportunity rover. Mars Lander is guided by a program, and right now the failure rate for landing on the NASA simulator is unacceptable.

This puzzle is the second level of the "Mars Lander" trilogy. The controls are the same as the previous level but you must now control the angle in order to succeed.
 	Rules
Built as a game, the simulator puts Mars Lander on a limited zone of Mars sky.

	The zone is 7000m wide and 3000m high.

There is a unique area of flat ground on the surface of Mars, which is at least 1000 meters wide.Every second, depending on the current flight parameters (location, speed, fuel ...), the program must provide the new desired tilt angle and thrust power of Mars Lander:
	Angle goes from -90° to 90° . Thrust power goes from 0 to 4 .
 The game simulates a free fall without atmosphere. Gravity on Mars is 3.711 m/s² . For a thrust power of X, a push force equivalent to X m/s² is generated and X liters of fuel are consumed. As such, a thrust power of 4 in an almost vertical position is needed to compensate for the gravity on Mars.

For a landing to be successful, the ship must:
land on flat ground
land in a vertical position (tilt angle = 0°)
vertical speed must be limited ( ≤ 40m/s in absolute value)
horizontal speed must be limited ( ≤ 20m/s in absolute value)
 	Note
Tests and validators are only slightly different. A program that passes a given test will pass the corresponding validator without any problem.
 	Game Input
The program must first read the initialization data from standard input. Then, within an infinite loop, the program must read the data from the standard input related to Mars Lander's current state and provide to the standard output the instructions to move Mars Lander.
Initialization input
Line 1: the number surfaceN of points used to draw the surface of Mars.
Next surfaceN lines: a couple of integers landX landY providing the coordinates of a ground point. By linking all the points together in a sequential fashion, you form the surface of Mars which is composed of several segments. For the first point, landX = 0 and for the last point, landX = 6999
Input for one game turn
A single line with 7 integers: X Y hSpeed vSpeed fuel rotate power
X,Y are the coordinates of Mars Lander (in meters).
hSpeed and vSpeed are the horizontal and vertical speed of Mars Lander (in m/s). These can be negative depending on the direction of Mars Lander.
fuel is the remaining quantity of fuel in liters. When there is no more fuel, the power of thrusters falls to zero.
rotate is the angle of rotation of Mars Lander expressed in degrees.
power is the thrust power of the landing ship.
Output for one game turn
A single line with 2 integers: rotate power :
rotate is the desired rotation angle for Mars Lander. Please note that for each turn the actual value of the angle is limited to the value of the previous turn +/- 15°.
power is the desired thrust power. 0 = off. 4 = maximum power. Please note that for each turn the value of the actual power is limited to the value of the previous turn +/- 1.
Constraints
2 ≤ surfaceN < 30
0 ≤ X < 7000
0 ≤ Y < 3000
-500 < hSpeed, vSpeed < 500
0 ≤ fuel ≤ 2000
-90 ≤ rotate ≤ 90
0 ≤ power ≤ 4
Response time per turn ≤ 100ms
'''