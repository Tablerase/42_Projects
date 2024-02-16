/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:25:34 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:47:01 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fractol_bonus.h"

/**
 * *Check fractal data and malloc need memory
 * Allocate memory for the fractal data into a char array
 * This array will be used to write the xpm file
 * @param: fractol structure
*/
static void	ft_check_fractal(t_fractol *fractol)
{
	if (fractol->fra.fractal_data != NULL)
	{
		free(fractol->fra.fractal_data);
		fractol->fra.fractal_data = NULL;
	}
	fractol->fra.fractal_data = \
		malloc(sizeof(char) * ((fractol->fra.fractal_data_len) + 1));
	if (fractol->fra.fractal_data == NULL)
	{
		ft_printf("Error malloc fractal data\n");
		ft_exit(fractol);
	}
	if (fractol->img.mlx_img != NULL)
	{
		mlx_destroy_image(fractol->mlx, fractol->img.mlx_img);
		fractol->img.mlx_img = NULL;
	}
}

/**
 * * Function to draw and config the fractal
 * @param: fractol structure
 * @param: fractal type
*/
void	ft_fractal(t_fractol *fractol)
{
	ft_check_fractal(fractol);
	if (ft_strncmp(fractol->fra.fractal_type, "mandelbrot", 10) == 0)
		ft_mandelbrot(fractol);
	if (ft_strncmp(fractol->fra.fractal_type, "julia", 5) == 0)
		ft_julia(fractol);
	if (ft_strncmp(fractol->fra.fractal_type, "burningship", 10) == 0)
		ft_burningship(fractol);
	ft_create_xpm(fractol);
	ft_xpm_image(fractol);
	ft_infos(fractol);
}
