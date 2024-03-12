# 42_Cub3D

## Notions

### Not Watched yet

- https://youtu.be/uSzGdfdOoG8?t=133 - Matrix Math for code

### Raycasting

#### Description

Raycasting is a rendering technique used to create a 3D perspective in a 2D map. It is often used in video games to create the illusion of 3D environments, such as in the classic game Wolfenstein 3D. Raycasting works by casting rays from the player's point of view and calculating the distance to the nearest wall in each direction. These distances are then used to determine the height of the walls in the 2D map, creating the illusion of depth and perspective.

#### Articles

- [🔦 2D Visibility - Webpage with demos and maths](https://www.redblobgames.com/articles/visibility/)
- [🧊 Raycasting - How to do in C - Using Wolfenstein as Example](https://lodev.org/cgtutor/raycasting.html)

#### Videos

- [🎥 Raycasting - The Coding Train - JS](https://thecodingtrain.com/challenges/145-ray-casting-2d)
- [🎥 Rendering Raycasting - The Coding Train - JS](https://www.youtube.com/watch?v=vYgIKn7iDH8)

#### Video Game

Play this game to see the concept of raycasting in action.

- [🕹️ Wolfenstein Online](http://users.atw.hu/wolf3d/)

<details>
<summary>Controls / Keys</summary>

##### Movements

- Arrow keys (←↑↓→)
- Shift : run fast
- Alt : Slide with movements insted of turning

##### Actions

- Ctrl : fire (in Wolfenstein)
- Space : 
    - Open doors / hidden rooms (in Wolfenstein)
    - Activate elevators (in Wolfenstein)
- [1 - 4] number keys :
    - Change weapon (in Wolfenstein)
    - Change item (in Wolfenstein)

</details>

### FishEye

<img src="https://upload.wikimedia.org/wikipedia/commons/1/10/Wood-1906_-_Fig_2.jpg" align="right" width="30%">

#### Description

Fisheye distortion is a type of optical distortion that occurs when a camera lens has a wide field of view. It causes straight lines to appear curved, and it can create a distorted, panoramic effect. Fisheye distortion is often used in photography and videography to create dramatic, wide-angle images, and it can also be used in computer graphics to create immersive, 3D environments.

[🔍 Fisheye Lens - Wikipedia](https://en.wikipedia.org/wiki/Fisheye_lens)

## Code

### KeyHooks

## Math

### Vector

[🔗 Vectors - MathIsFun](https://www.mathsisfun.com/algebra/vectors.html)

<table>
  <tr>
    <td>
      <img src="https://www.mathsisfun.com/algebra/images/vector-mag-dir.svg?sanitize=true" width="50%">
    </td>
    <td>
      <img src="https://www.mathsisfun.com/algebra/images/vector-notation.svg?sanitize=true" width="50%">
    </td>
  </tr>
  <tr>
    <td>
      <ul>
        <li>
          <b>Magnitude</b> : The length of the line.

$\ |A| = \sqrt{{a_x}^2 + {a_y}^2} $
        </li>
        <li>
          <b>Direction</b> : The direction the line is pointing.
        </li>
      </ul>
    </td>
    <td>
      <ul>
        <li>
          <b>Notation</b> : The vector is often written in <b>bold</b> or with an arrow on top.
        </li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>
      <img src="https://www.mathsisfun.com/algebra/images/vector-cartesian.svg?sanitize=true" width="50%">
    </td>
    <td>
      <img src="https://www.mathsisfun.com/algebra/images/vector-polar.svg?sanitize=true" width="35%">
    </td>
  </tr>
  <tr>
    <td>
      <ul>
        <li>
          <b>Cartesian Coordinates</b> :

$\ a = \begin{bmatrix} a_x \\ a_y \end{bmatrix} $
        </li>
      </ul>
    </td>
    <td>
      <ul>
        <li>
          <b>Polar Coordinates</b> :

$\ a = \begin{bmatrix} r \\ θ \end{bmatrix} $
        </li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>
      <img src="https://www.mathsisfun.com/algebra/images/vector-add.svg?sanitize=true" width="50%">
    </td>
    <td>
      <img src="https://www.mathsisfun.com/algebra/images/vector-subtract.svg?sanitize=true" width="50%">
    </td>
  </tr>
  <tr>
    <td>
      <ul>
        <li>
          <b>Addition</b> : Adding two vectors.
        </li>
      </ul>
    </td>
    <td>
      <ul>
        <li>
          <b>Subtraction</b> : Subtracting two vectors.
        </li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>
      <div style="display: flex; justify-content: space-between;">
        <img src="https://www.mathsisfun.com/algebra/images/dot-product-1.svg?sanitize=true">
        <img src="https://www.mathsisfun.com/algebra/images/dot-product-2.svg?sanitize=true">
      </div>
    </td>
    <td>
      <img src="https://www.mathsisfun.com/algebra/images/cross-product.svg?sanitize=true" width="40%">
      <img src="https://www.mathsisfun.com/algebra/images/cross-product-components.svg?sanitize=true" width="50%">
    </td>
  </tr>
  <tr>
    <td>
      <ul>
        <li>
          <b>Dot Product</b> : The dot product of two vectors is a scalar.
        </li>
      </ul>
    </td>
    <td>
      <ul>
        <li>
          <b>Cross Product</b> : The cross product of two vectors is a vector.
        </li>
      </ul>
    </td>
  </tr>
</table>

### Matrix

<details>
<summary>More infos / Refresher </summary>

#### Description

In mathematics, a matrix is a rectangular array of numbers or other values, organized into rows and columns. Matrices are used to represent and manipulate data in various fields of mathematics, including linear algebra, numerical analysis, geometry, graph theory, statistics, and many others.

Here are some common uses of matrices:

- `Representation of linear systems of equations`: Matrices can be used to represent and solve systems of linear equations. Each row of the matrix represents an equation, and each column represents a variable.
- `Linear transformations`: Matrices can be used to represent linear transformations, such as rotations, scalings, and translations in space.
- `Representation of graphs`: Matrices can be used to represent graphs, where the elements of the matrix indicate the connections between the vertices of the graph.
- `Data analysis`: Matrices can be used to represent multidimensional data, such as images or time series, and to perform operations on this data, such as dimensionality reduction or classification.
- `Computer graphics`: Matrices are used to represent and manipulate 3D objects in computer graphics, such as transformations, projections, and lighting calculations.

In summary, matrices are a powerful and versatile tool in mathematics that can be used to represent and manipulate data in many different fields.

#### Calculation

- [🔗 Matrix - MathIsFun](https://www.mathsisfun.com/algebra/matrix-multiplying.html)
  - Matrix Scalar Multiplication :

  ![Matrix Scalar](https://www.mathsisfun.com/algebra/images/matrix-multiply-constant.svg?sanitize=true)

  `2` in the above example is the **scalar**.
  - Matrix multiplication :
<div align="center" style="display: flex; ">
  <img src="https://www.mathsisfun.com/algebra/images/matrix-multiply-a.svg" width="50%" style="padding: 5px; ">
  <img src="https://www.mathsisfun.com/algebra/images/matrix-multiply-b.svg" width="60%" style="padding: 5px: ">
</div>

#### Determinant

- [🔗 Matrix Determinant - MathIsFun](https://www.mathsisfun.com/algebra/matrix-determinant.html)

It is a special number that can be calculated from the elements of a square matrix. It is used in various areas of mathematics and has many applications in science and engineering. The determinant can be reprensented as a function `det(A)` or `|A|` (not the same as absolute).

As a formula (remember the vertical bars `||` mean "determinant of")

$$
A =
\begin{vmatrix}
a & b \\
c & d
\end{vmatrix}
=
ad - bc
$$

$$
B =
\begin{vmatrix}
a & b & c \\
d & e & f \\
g & h & i
\end{vmatrix}
=
a \begin{vmatrix}
e & f \\
h & i
\end{vmatrix}
- b \begin{vmatrix}
d & f \\
g & i
\end{vmatrix}
+ c \begin{vmatrix}
d & e \\
g & h
\end{vmatrix}
= a(ei - fh) - b(di - fg) + c(dh - eg)
$$

To calculate higher order determinants, we can use the following formula:

$$
\begin{vmatrix}
a & b & c & d \\
e & f & g & h \\
i & j & k & l \\
m & n & o & p
\end{vmatrix}
= a \begin{vmatrix}
f & g & h \\
j & k & l \\
n & o & p
\end{vmatrix}
- b \begin{vmatrix}
e & g & h \\
i & k & l \\
m & o & p
\end{vmatrix}
+ c \begin{vmatrix}
e & f & h \\
i & j & l \\
m & n & p
\end{vmatrix}
- d \begin{vmatrix}
e & f & g \\
i & j & k \\
m & n & o
\end{vmatrix}
$$

<div align="center">
  <img src="https://www.mathsisfun.com/algebra/images/matrix-4x4-det.svg" width="50%">
</div>

This method of calculating determinants is called the **cofactor expansion** or **Laplace expansion**. Notice the alternating signs in front of each term. (+, -, +, -, ...)

##### Usages

The determinant of a matrix can be used to determine whether the matrix has an inverse, to solve systems of linear equations, and to calculate the volume of a parallelepiped in three-dimensional space, among other things.

In computer science and graphics, determinants are used in various applications, especially in 3D computer graphics, computer vision, and robotics. Here are some examples:

- `Transformation matrices`: Determinants are used to calculate the scale factor of a transformation matrix. In computer graphics, transformation matrices are used to transform objects in 3D space, such as scaling, rotation, and translation. The determinant of the transformation matrix can be used to determine whether the transformation preserves the orientation of the object or not.
- `Camera projection`: Determinants are used in camera projection matrices to map 3D points to 2D points on the screen. The projection matrix is used to transform the 3D coordinates of a point in the world to 2D coordinates on the screen. The determinant of the projection matrix can be used to determine whether the projection is invertible or not.
- `Collision detection`: Determinants are used in collision detection algorithms to determine whether two objects intersect or not. In 3D computer graphics, objects are often represented as meshes of triangles. The determinant of the matrix formed by the vertices of a triangle can be used to determine whether the triangle is degenerate or not, which is important in collision detection.
- `Robotics`: Determinants are used in robotics to calculate the kinematics and dynamics of robotic systems. The determinant of the Jacobian matrix can be used to determine whether a robotic system is singular or not, which is important in robot control.

In summary, determinants are an important tool in computer science and graphics, especially in 3D computer graphics, computer vision, and robotics. They are used in various applications, such as transformation matrices, camera projection, collision detection, and robotics.

</details>

### Intersection

#### Line-Line Intersection

<details>
<summary>Details</summary>

<div align="center" style=" display: flex;" >
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Line-Line_Intersection.png/400px-Line-Line_Intersection.png">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/d7/Is-linesegm.svg/300px-Is-linesegm.svg.png" width="50%">
</div>

- [🔗 Line-Line Intersection / Segments - Wikipedia](https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection)

In order to find the position of the intersection in respect to the line segments, we can define lines $L_1$ and $L_2$ in terms of [first degree Bézier](https://en.wikipedia.org/wiki/B%C3%A9zier_curve#Linear_curves) parameters:

$$
L_1 =   \begin{bmatrix}x_1     \\ y_1\end{bmatrix}
    + t \begin{bmatrix}x_2-x_1 \\ y_2-y_1\end{bmatrix},
\qquad
L_2 =   \begin{bmatrix}x_3     \\ y_3\end{bmatrix}
    + u \begin{bmatrix}x_4-x_3 \\ y_4-y_3\end{bmatrix}
$$

(where $t$ and $u$ are real numbers). The intersection point of the lines is found with one of the following values of $t$ or $u$, where

$$
t = \frac{(x_1 - x_3)(y_3-y_4)-(y_1-y_3)(x_3-x_4)}{(x_1-x_2)(y_3-y_4)-(y_1-y_2)(x_3-x_4)}
$$

and

$$
u = -\frac{(x_1 - x_2)(y_1-y_3)-(y_1-y_2)(x_1-x_3)}{(x_1-x_2)(y_3-y_4)-(y_1-y_2)(x_3-x_4)},
$$

with

$$
(P_x, P_y)= (x_1 + t (x_2-x_1), y_1 + t (y_2-y_1)) \quad \text{or} \quad (P_x, P_y) = (x_3 + u (x_4-x_3), y_3 + u (y_4-y_3))
$$

There will be an intersection if $0 \leq t \leq 1$ and $0 \leq u \leq 1$. The intersection point falls within the first line segment if $0 \leq t \leq 1$, and it falls within the second line segment if $0 \leq u \leq 1$. These inequalities can be tested without the need for division, allowing rapid determination of the existence of any line segment intersection before calculating its exact point.

#### In our case

We can use the following formula to find the intersection point of two line segments:

$$
t = \frac{(x_1 - x_3)(y_3-y_4)-(y_1-y_3)(x_3-x_4)}{(x_1-x_2)(y_3-y_4)-(y_1-y_2)(x_3-x_4)}
$$

$$
u = -\frac{(x_1 - x_2)(y_1-y_3)-(y_1-y_2)(x_1-x_3)}{(x_1-x_2)(y_3-y_4)-(y_1-y_2)(x_3-x_4)}
$$

$$
(P_x, P_y)= (x_1 + t (x_2-x_1), y_1 + t (y_2-y_1)) \quad \text{or} \quad (P_x, P_y) = (x_3 + u (x_4-x_3), y_3 + u (y_4-y_3))
$$

If you notice the denominator of the two formulas are the same, so we can calculate it once and use it for both formulas.

$$
denom = (x_1-x_2)(y_3-y_4)-(y_1-y_2)(x_3-x_4)
$$

If `denom` is equal to `0`, then the two lines are parallel and will never intersect.

now we can calculate `t` and `u`:

$$
t = \frac{(x_1 - x_3)(y_3-y_4)-(y_1-y_3)(x_3-x_4)}{denom}
$$

$$
u = -\frac{(x_1 - x_2)(y_1-y_3)-(y_1-y_2)(x_1-x_3)}{denom}
$$


We then check if $0 \leq t \leq 1$ and $u \geq 0$ (because we are looking for intersection on `t` segment and we dont care if it's not on the `u` associated segments). If both conditions are true, then the two line segments intersect, and the intersection point is given by: 

$$
(P_x, P_y)= (x_1 + t (x_2-x_1), y_1 + t (y_2-y_1))
$$

$$
P_x = x_1 + t (x_2-x_1)
$$

$$
P_y = y_1 + t (y_2-y_1)
$$

[🧮 Explanations](https://youtu.be/TOEi6T2mtHo?t=666)

</details>

### Shapes
📐 [Shapes in C](http://www.brackeen.com/vga/shapes.html#6)

#### Line

##### Bresenham's Line Algorithm

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/a/ab/Bresenham.svg/300px-Bresenham.svg.png" align="right">

Algorithm to draw a line between two points. It is faster than the naive approach of calculating the slope and then drawing the line. The algorithm is based on the idea of determining the nearest pixel to the ideal line at each step.

The reason Bresenham's line drawing algorithm is faster is that it uses no float multiplication or division. Multiplication and division are slow on a computer, even on a computer with a math coprocessor.

###### Algorithm (slope between 0 and 1)

Use the slope to determine the next pixel to draw with a decision parameter.
  - The slope is the ratio of the change in the y-coordinates to the change in the x-coordinates.
  - The decision parameter is used to determine which pixel to draw next. It act as a threshold to determine if the next pixel is above or below the ideal line.

$$ slope = \frac{rise}{run} = \frac{Δy}{Δx} $$

$$ slope = \frac{y_2 - y_1}{x_2 - x_1} $$

The decision parameter is used to determine which pixel to draw next. The decision parameter is calculated as follows:

$$ P_k = 2Δy - Δx $$

If $P_k < 0$, the next pixel is $(x_k + 1, y_k)$ and $P_{k+1} = P_k + 2Δy$.

If $P_k \geq 0$, the next pixel is $(x_k + 1, y_k + 1)$ and $P_{k+1} = P_k + 2Δy - 2Δx$.

The algorithm starts at the first point and draws the line to the second point. At each step, it calculates the decision parameter and uses it to determine which pixel to draw next. The algorithm continues until it reaches the second point.

- [📏 Bresenham - Explained](https://digitalbunker.dev/bresenhams-line-algorithm/)
- [📏 Bresenham - Algo integer arithmetic - Wikipedia](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#Algorithm_for_integer_arithmetic)
