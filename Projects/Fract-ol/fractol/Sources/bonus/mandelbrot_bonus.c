/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:27:53 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:47:01 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fractol_bonus.h"

/*
* Mandelbrot fractal
Z = a + bi
Set:
Z = Z^2 + c

Set start at Z = 0, so Z = c2 + c, c = a + bi
Z = (a + bi)^2 + c

Z = a^2 + 2abi - b^2 + c
aa = a^2 - b^2
bb = 2abi

Z = aa + bb + c

Magnitude of a complex number:
|Z| = sqrt(a^2 + b^2)
*/

/**
 * * Calculate if a point is in the mandelbrot set
 * @param: Param storage is the scaled_y
 * @param: x, y coordinates of the point to scale into complex plane (-2, 2)
 * @return: the number of iterations before the point diverge
 * fra x and y are the coordinates of the center of the screen
 * scaled_x and scaled_y are the coordinates of the point
 * to scale into complex plane

*/
static int	ft_mandelbrot_set(
	double x,
	double y,
	t_fractol *fractol,
	int count)
{
	double	scaled_x;
	double	real;
	double	imaginary;
	double	a;
	double	b;

	scaled_x = fractol->fra.x + (x - WIDTH / 2) * fractol->fra.zoom / WIDTH;
	fractol->fra.param_storage = fractol->fra.y + \
		(y - HEIGHT / 2) * fractol->fra.zoom / HEIGHT;
	a = 0;
	b = 0;
	count = 0;
	while (count < fractol->fra.max_iterations)
	{
		real = (a * a) - (b * b);
		imaginary = 2 * a * b;
		a = real + scaled_x;
		b = imaginary + fractol->fra.param_storage;
		if (b + a > 4)
			return (count);
		count++;
	}
	return (count);
}

/**
 * * Draw mandelbrot fractal
 * @param: fractol
*/
void	ft_mandelbrot(t_fractol *fractol)
{
	double	x;
	double	y;
	int		iter;

	iter = 0;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iter = ft_mandelbrot_set(x, y, fractol, iter);
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

// Mandelbrot fractal v1 - without image / zoom / move
// /**
//  * * Calculate if a point is in the mandelbrot set
//  * @param:  x, y coordinates of the point to scale into complex plane (-2, 2)
//  * @return: the number of iterations before the point diverge
// */ 
// int	ft_mandelbrot_set(double x, double y, int max_iterations)
// {
// 	double	scaled_x;
// 	double	scaled_y;
// 	double	real;
// 	double	imaginary;
// 	double	a;
// 	double	b;
// 	int		count;

// 	scaled_x = (x - WIDTH / 2) * 4 / WIDTH;
// 	scaled_y = (y - HEIGHT / 2) * 4 / HEIGHT;
// 	a = 0;
// 	b = 0;
// 	count = 0;
// 	while (count < max_iterations)
// 	{
// 		real = (a * a) - (b * b);
// 		imaginary = 2 * a * b;
// 		a = real + scaled_x;
// 		b = imaginary + scaled_y;
// 		if (b + a > 4)
// 			return (count);
// 		count++;
// 	}
// 	return (count);
// }

// /**
//  * * Draw mandelbrot fractal
//  * @param: fractol
// */
// void	ft_mandelbrot(t_fractol *fractol)
// {
// 	double	x;
// 	double	y;
// 	int		iterations;

// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		y = 0;
// 		while (y < HEIGHT)
// 		{
// 			iterations = ft_mandelbrot_set(x, y, fractol->max_iterations);
// 			if (iterations == fractol->max_iterations)
// 				mlx_pixel_put(fractol->mlx, fractol->win, x, y, C_WHITE);
// 			else
// 				mlx_pixel_put(fractol->mlx, fractol->win, x, y, 
// 					ft_colormode(iterations, fractol));
// 			y++;
// 		}
// 		x++;
// 	}
// 	ft_infos(fractol);
// }
