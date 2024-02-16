/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:18:47 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:36:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fractol.h"

/**
 * * Initiate the mlx setup for fractol
 * Create the window and the image
 * @param: fractol structure
*/
int	ft_create_window(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		return (ft_printf("Error initiating mlx graphics\n"), exit(0), 0);
	}
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Cute Fract-ol");
	if (fractol->win == NULL)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		free(fractol->mlx);
		return (ft_printf("Error creating window\n"), exit(0), 0);
	}
	return (1);
}

/**
 * * Program shutdown
 * Free memory and exit program
 * @param: fractol structure
*/
int	ft_exit(t_fractol *fractol)
{
	if (fractol->fra.fractal_data != NULL)
		free(fractol->fra.fractal_data);
	if (fractol->img.mlx_img != NULL)
		mlx_destroy_image(fractol->mlx, fractol->img.mlx_img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	ft_printf("%s ######### Program Closed ######### \n%s", MAG, RESET);
	free(fractol->mlx);
	exit(0);
}
