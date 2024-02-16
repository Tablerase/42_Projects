/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:48:43 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:36:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Julia fractal

* Complex number:
Z = a + bi or Z = x + yi
x = real part
yi = imaginary part

i^2 = -1
i = sqrt(-1)

* Z Sets:
Z = Z^2 + c
c = Julia set

* Julia set:
Exemple of set : c = -0.8 + 0.156i

The Julia set is a fractal defined by a complex number c. 
The set is obtained by iterating the function f(z) = z^2 + c.
For each point c, the set of points z that do not diverge
under iteration are plotted in the complex plane. 
The set's boundary is a fractal, which means that it has a fine structure 
at arbitrarily small scales.

The key difference between the Mandelbrot set and the Julia set is that
the Mandelbrot set uses the coordinates of the point in the complex plane
to determine if the point is in the set, while the Julia set uses a
constant value for all the points in the set.

* Arbitrary threshold for the Magnitude of the set:
if the absolute value of Z is greater than 2, then Z is divergent
if the absolute value of Z is less than 2, then Z is convergent

* Magnitude of a complex number:
|Z| = sqrt(a^2 + b^2)
*/

#include "../../Includes/fractol.h"

/**
 * * Fill julia fractal infos
 * @param: fractol structure
*/
void	ft_fill_julia(t_fractol *fractol)
{
	fractol->fra.fractal_type = "julia";
	fractol->fra.c_imaginary = 0.156;
	fractol->fra.c_real = -0.8;
}

/**
 * * Check the arguments for julia fractal
 * Read the args and recover the values
 * Check if the values are valid
 * @param: arguments
*/
void	ft_check_julia_args(char **argv, t_fractol *fractol)
{
	double	c_real;
	double	c_imaginary;

	if (argv[2] == NULL || argv[3] == NULL)
		ft_args_error();
	else
	{
		c_real = ft_atof(argv[2]);
		c_imaginary = ft_atof(argv[3]);
		if (c_imaginary < -2 || c_imaginary > 2)
			ft_args_error();
		if (c_real < -2 || c_real > 2)
			ft_args_error();
		fractol->fra.c_real = c_real;
		fractol->fra.c_imaginary = c_imaginary;
		fractol->fra.fractal_type = "julia";
	}
}

/**
 * * Calculate if a point is in the julia set
 * We initiate the complex number Z to the coordinates of the point in the
 * complex plane, then we iterate the function f(z) = z^2 + c. 
 * With c constant.
 * @param:  x, y coordinates of the point to scale into complex plane (-2, 2)
 * @return: the number of iterations before the point diverge
 * fra x and y are the coordinates of the center of the screen
 * scaled_x and scaled_y are the coordinates of the point
 * to scale into complex plane
*/
static int	ft_julia_set(double x, double y, t_fractol *fractol)
{
	double	real;
	double	imaginary;
	double	a;
	double	b;
	int		count;

	a = fractol->fra.x + (x - WIDTH / 2) * fractol->fra.zoom / WIDTH;
	b = fractol->fra.y + (y - HEIGHT / 2) * fractol->fra.zoom / HEIGHT;
	count = 0;
	while (count < fractol->fra.max_iterations)
	{
		real = (a * a) - (b * b);
		imaginary = 2 * a * b;
		a = real + fractol->fra.c_real;
		b = imaginary + fractol->fra.c_imaginary;
		if (b + a > 2)
			return (count);
		count++;
	}
	return (count);
}

/**
 * * Draw julia fractal
 * @param: fractol structure
*/
void	ft_julia(t_fractol *fractol)
{
	double	x;
	double	y;
	int		iter;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iter = ft_julia_set(x, y, fractol);
			if (iter == fractol->fra.max_iterations)
				fractol->fra.fractal_data[(int)(x + y * WIDTH)] = \
					fractol->col.color_array[fractol->col.color_number - 1];
			else
				fractol->fra.fractal_data[(int)(x + y * WIDTH)] = \
					fractol->col.color_array[ft_colormode(iter, fractol)];
			y++;
		}
		x++;
	}
}
