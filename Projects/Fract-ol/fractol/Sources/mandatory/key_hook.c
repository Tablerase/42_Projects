/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:52:59 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:36:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fractol.h"

/**
 * * Choose palette of colors
 * Change color key 'c'
 * Act as a switch between palettes
 * @param: fractol structure
*/
static void	ft_palette_change(t_fractol *fractol)
{
	if (ft_strncmp(fractol->col.palette_name, PALETTE_1_NAME, 13) == 0)
	{
		fractol->col.palette_name = PALETTE_2_NAME;
		fractol->col.color_palette = PALETTE_2;
		fractol->col.color_array = PALETTE_2_ARRAY;
		fractol->col.color_number = ft_strlen(fractol->col.color_array);
	}
	else if (ft_strncmp(fractol->col.palette_name, PALETTE_2_NAME, 7) == 0)
	{
		fractol->col.palette_name = PALETTE_3_NAME;
		fractol->col.color_palette = PALETTE_3;
		fractol->col.color_array = PALETTE_3_ARRAY;
		fractol->col.color_number = ft_strlen(fractol->col.color_array);
	}
	else if (ft_strncmp(fractol->col.palette_name, PALETTE_3_NAME, 20) == 0)
	{
		fractol->col.palette_name = PALETTE_1_NAME;
		fractol->col.color_palette = PALETTE_1;
		fractol->col.color_array = PALETTE_1_ARRAY;
		fractol->col.color_number = ft_strlen(fractol->col.color_array);
	}
}

/**
 * * Choose fractal type
 * Change fractal type key 'space'
 * Act as a switch between fractals
 * @param: fractol structure
*/
static void	ft_fractal_change(t_fractol *fractol)
{
	if (ft_strncmp(fractol->fra.fractal_type, "mandelbrot", 10) == 0)
	{
		fractol->fra.fractal_type = "julia";
		ft_fill_julia(fractol);
	}
	else if (ft_strncmp(fractol->fra.fractal_type, "julia", 5) == 0)
		fractol->fra.fractal_type = "mandelbrot";
}

/**
 * * Zoom in and out
 * Zoom key '+' and '-'
 * @param: fractol structure
 * @param: keycode
*/
static void	ft_zoom(t_fractol *fractol, int keycode)
{
	if (keycode == XK_KP_Add)
		fractol->fra.zoom /= 1.2;
	else if (keycode == XK_KP_Subtract)
		fractol->fra.zoom *= 1.2;
}

// Handle keyboard events
int	ft_keyhooks(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape)
		return (ft_exit(fractol), 0);
	if (keycode == XK_space)
	{
		ft_fractal_change(fractol);
		ft_fractal(fractol);
	}
	if (keycode == XK_c)
	{
		ft_palette_change(fractol);
		ft_fractal(fractol);
	}
	if (keycode == XK_KP_Add || keycode == XK_KP_Subtract)
	{
		ft_zoom(fractol, keycode);
		ft_fractal(fractol);
	}
	return (1);
}
