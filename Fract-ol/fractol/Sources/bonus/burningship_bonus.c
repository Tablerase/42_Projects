/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:45:18 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:47:01 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fractol_bonus.h"

/*
Burningship fractal vs Mandelbrot fractal
The difference between this calculation and that for the Mandelbrot set,
is that the real and imaginary components are set to their 
respective absolute values before squaring at each iteration.
*/

/**
 * * Calculate if a point is in the burningship set
 * @param: Param storage is the scaled_y
*/
static int	ft_burningship_set(
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
	fractol->fra.param_storage = fractol->fra.y
		+ (y - HEIGHT / 2) * fractol->fra.zoom / HEIGHT;
	a = 0;
	b = 0;
	count = 0;
	while (count < fractol->fra.max_iterations)
	{
		real = (a * a) - (b * b);
		imaginary = 2 * a * b;
		a = fabs(real + scaled_x);
		b = fabs(imaginary + fractol->fra.param_storage);
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
void	ft_burningship(t_fractol *fractol)
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
			iter = ft_burningship_set(x, y, fractol, iter);
			if (iter == fractol->fra.max_iterations)
				fractol->fra.fractal_data[(int)(x + y * WIDTH)]
					= fractol->col.color_array[fractol->col.color_number - 1];
			else
				fractol->fra.fractal_data[(int)(x + y * WIDTH)]
					= fractol->col.color_array[ft_colormode(iter, fractol)];
			y++;
		}
		x++;
	}
}

// void draw_line(int x0, int y0, int x1, int y1, t_fractol *fractol)
// {
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx = (x0 < x1) ? 1 : -1;
//     int sy = (y0 < y1) ? 1 : -1;
//     int err = dx - dy;

//     while (1)
//     {
//         fractol->fra.fractal_data[y0 * WIDTH + x0]
//			  = fractol->col.color_array[fractol->col.color_number - 1];
//         if (x0 == x1 && y0 == y1)
//             break;
//         int e2 = 2 * err;
//         if (e2 > -dy)
//         {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dx)
//         {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }

// /**
//  * * Calculate if a point is in the sierpinski set
//  * @param: x, y coordinates of the point to scale into complex plane (-2, 2)
// */
// static void ft_sierpinski_set(
// 	double x,
// 	double y,
// 	t_fractol *fractol,
// 	int size)
// {
// 	if (size < 5)
// 		return ;
// 	draw_line(x, y, x - size / 2, y, fractol);
//     draw_line(x, y, x + size / 2, y, fractol);
//     draw_line(x, y, x, y - size / 2, fractol);
// 	ft_sierpinski_set(x - size / 2, y, fractol, size / 2);
// 	ft_sierpinski_set(x + size / 2, y, fractol, size / 2);
// 	ft_sierpinski_set(x, y - size / 2, fractol, size / 2);
// }

// /**
//  * * Function to draw the sierpinski fractal
//  * @param: fractol structure
//  */
// void	ft_sierpinski(t_fractol *fractol)
// {
// 	int		size = 200;

// 	ft_memset(fractol->fra.fractal_data, '0', fractol->fra.fractal_data_len);
// 	ft_sierpinski_set(WIDTH / 2, HEIGHT / 2, fractol, size);
// }
