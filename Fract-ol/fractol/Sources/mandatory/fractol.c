/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:09:31 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:36:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Arguments
The type of fractal to display and any other option available

External functs.
• open, close, read, write, malloc, free, perror, strerror, exit
• All functions of the math library (-lm compiler option, man man 3 math)
• All functions of the MiniLibX
• ft_printf and any equivalent
YOU coded

Libft authorized: Yes

Description
This project is about creating a small fractal exploration program.
First, you have to know what a fractal is.
*/

#include "../../Includes/fractol.h"

/**
 * * Check the arguments
 * Apply the arguments to the fractol structure
 * @param: number of arguments
 * @param: arguments
 * @param: fractol structure
 * @output: error message if the arguments are not valid
*/
void	ft_check_args(int argc, char **argv, t_fractol *fractol)
{
	if (argc < 2)
		ft_args_error();
	else if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) != 0
			&& ft_strncmp(argv[1], "julia", 5) != 0)
			ft_args_error();
		if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
			fractol->fra.fractal_type = "mandelbrot";
		if (ft_strncmp(argv[1], "julia", 5) == 0)
			ft_fill_julia(fractol);
	}
	else if (argc > 2 && argc < 5)
	{
		if (ft_strncmp(argv[1], "julia", 5) != 0)
			ft_args_error();
		if (ft_strncmp(argv[1], "julia", 5) == 0)
			ft_check_julia_args(argv, fractol);
	}
	else
		ft_args_error();
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	ft_check_args(argc, argv, &fractol);
	ft_fill_structure(&fractol);
	ft_create_window(&fractol);
	mlx_hook(fractol.win, DestroyNotify, NoEventMask, ft_exit, &fractol);
	mlx_key_hook(fractol.win, ft_keyhooks, &fractol);
	mlx_hook(fractol.win, MotionNotify, PointerMotionMask, \
		ft_display_mouse_pos, &fractol);
	mlx_mouse_hook(fractol.win, ft_mouse_hooks, &fractol);
	ft_fractal(&fractol);
	mlx_loop(fractol.mlx);
	ft_exit(&fractol);
	return (0);
}
