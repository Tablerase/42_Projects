# Binary Space Partitioning

## Introduction

Binary Space Partitioning (BSP) is a technique used in computer graphics to divide a space into two regions. It is commonly used in 3D rendering to divide a scene into two regions, one that is visible to the camera and one that is not. This allows for efficient rendering of complex scenes by only rendering the parts of the scene that are visible to the camera.

## How it works

BSP works by dividing a space into two regions using a plane. The plane is defined by a normal vector and a distance from the origin. The normal vector defines the orientation of the plane, and the distance from the origin defines the position of the plane in space. The space is then divided into two regions, one on each side of the plane. Each region can then be further subdivided using additional planes, creating a binary tree structure that divides the space into smaller and smaller regions.

<img src="https://media.geeksforgeeks.org/wp-content/uploads/20200630014725/space.jpg" title="schema bsp">
