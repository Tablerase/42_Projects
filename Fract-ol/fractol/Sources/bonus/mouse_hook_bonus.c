/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:43:30 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:47:01 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fractol_bonus.h"

/**
 * * Mouse position
 * @param: x coordinate
 * @param: y coordinate
 * @param: fractol structure
*/
int	ft_display_mouse_pos(int mouse_x, int mouse_y, t_fractol *fractol)
{
	mlx_mouse_get_pos(fractol->mlx, fractol->win, &mouse_x, \
		&mouse_y);
	fractol->fra.mouse_x = mouse_x;
	fractol->fra.mouse_y = mouse_y;
	ft_infos(fractol);
	return (0);
}

/**
 * * Zoom in and out on the mouse position
 * @param: mouse button
 * @param: x coordinate (mouse x)
 * @param: y coordinate (mouse y)
 * @param: fractol structure
 * Calculate the new x and y coordinates in the complex plane
 * Addition to previous x and y coordinates
 because previous x and y coordinates are the center of the screen
*/
static void	ft_mouse_zoom(int button, int x, int y, t_fractol *fractol)
{
	fractol->fra.mouse_x = x;
	fractol->fra.mouse_y = y;
	fractol->fra.x += (x - WIDTH / 2) * (fractol->fra.zoom / WIDTH);
	fractol->fra.y += (y - HEIGHT / 2) * (fractol->fra.zoom / HEIGHT);
	if (button == 4)
	{
		fractol->fra.zoom /= 1.2;
		ft_fractal(fractol);
	}
	if (button == 5)
	{
		fractol->fra.zoom *= 1.2;
		ft_fractal(fractol);
	}
}

/**
 * * Print the mouse position
 * @param: x coordinate
 * @param: y coordinate
 * @param: fractol structure
*/
static void	ft_print_cursor_pos(int x, int y, t_fractol *fractol)
{
	ft_printf("x: %d, y: %d\n", x, y);
	(void)fractol;
}

/**
 * * Mouse hook management
 * @param: mouse button
 * @param: mouse x coordinate
 * @param: mouse y coordinate
 * @param: fractol structure
*/
int	ft_mouse_hooks(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4 || button == 5)
		ft_mouse_zoom(button, x, y, fractol);
	if (button == 1)
		ft_print_cursor_pos(x, y, fractol);
	return (0);
}
