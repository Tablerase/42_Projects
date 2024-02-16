/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:00:55 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:36:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fractol.h"

/**
 * * Rectangle to erase the previous mouse position
 * @param: fractol structure
*/
static void	ft_pos_background(t_fractol *fractol)
{
	int	x;
	int	x_max;
	int	y;
	int	y_max;

	x = fractol->width - 65;
	x_max = fractol->width - 10;
	y = 4;
	y_max = 18;
	while (y < y_max)
	{
		while (x < x_max)
		{
			mlx_pixel_put(fractol->mlx, fractol->win, x, y, C_GREY);
			x++;
		}
		x = fractol->width - 65;
		y++;
	}
}

/**
 * * Display mouse position on the window
 * Draw a background rectangle to erase the previous mouse position
 * Then display the new mouse position
 * @param: mouse x coordinate from fractol structure
 * @param: mouse y coordinate from fractol structure
*/
void	ft_infos_mouse_position(t_fractol *fractol)
{
	char	*mouse_position;
	char	*mouse_position2;

	mlx_string_put(fractol->mlx, fractol->win, fractol->width - 155, \
		15, C_WHITE, "Mouse position: ");
	ft_pos_background(fractol);
	mouse_position = ft_itoa(fractol->fra.mouse_x);
	mlx_string_put(fractol->mlx, fractol->win, fractol->width - 60, \
		15, C_WHITE, mouse_position);
	free(mouse_position);
	mlx_string_put(fractol->mlx, fractol->win, fractol->width - 40, \
		15, C_WHITE, ", ");
	mouse_position2 = ft_itoa(fractol->fra.mouse_y);
	mlx_string_put(fractol->mlx, fractol->win, fractol->width - 30, \
		15, C_WHITE, mouse_position2);
	free(mouse_position2);
}

/**
 * *Display infos on the window
 * @param:  window, graphic server
*/
void	ft_infos(t_fractol *fractol)
{
	mlx_string_put(fractol->mlx, fractol->win, 10, 15, C_WHITE,
		"### Fract-ol ###");
	mlx_string_put(fractol->mlx, fractol->win, 10, 30, C_WHITE,
		"Fractal: ");
	mlx_string_put(fractol->mlx, fractol->win, 80, 30, C_WHITE,
		fractol->fra.fractal_type);
	mlx_string_put(fractol->mlx, fractol->win, 10, 45, C_GREY,
		"Esc: Exit program");
	mlx_string_put(fractol->mlx, fractol->win, 10, 60, C_GREY,
		"c: Change color");
	mlx_string_put(fractol->mlx, fractol->win, 10, 75, C_GREY,
		"Space: Change fractal");
	ft_infos_mouse_position(fractol);
}

/**
 * * Arguments error message
 * @output: error message if the arguments are not valid
*/
void	ft_args_error(void)
{
	ft_printf("%sUsage: ./fractol [fractal]\n%s", BRED, RESET);
	ft_printf("%sAvailable fractals: %s", YEL, RESET);
	ft_printf("%smandelbrot, julia\n%s", YEL, RESET);
	ft_printf("For julia optional sets: \n");
	ft_printf("./fractol julia \"real_part\" \"imaginary_part\"\n");
	ft_printf("Real and Imaginary parts must be between -2 and 2\n");
	ft_printf("Example: \n");
	ft_printf("./fractol julia -0.8 0.1\n");
	exit(0);
}
