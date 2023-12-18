/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:55:15 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:43:50 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fractol.h"

/**
 * * Initiate fractol structure
 * Fill the structure with needed paramaters
 * Prevents from segfaults and use of uninitialized variables
 * fractal_type : already filled(argv[1])
 * @param: fractol structure
*/
void	ft_fill_structure(t_fractol *fractol)
{
	fractol->width = WIDTH;
	fractol->height = HEIGHT;
	fractol->mlx = NULL;
	fractol->win = NULL;
	fractol->fra.zoom = 4;
	fractol->fra.x = 0;
	fractol->fra.y = 0;
	fractol->fra.mouse_x = 0;
	fractol->fra.mouse_y = 0;
	fractol->fra.param_storage = 0;
	fractol->fra.max_iterations = 50;
	fractol->fra.fractal_data = NULL;
	fractol->fra.fractal_data_len = WIDTH * HEIGHT;
	fractol->col.color_mode = "escape_time";
	fractol->col.palette_name = PALETTE_1_NAME;
	fractol->col.color_palette = PALETTE_1;
	fractol->col.color_array = PALETTE_1_ARRAY;
	fractol->col.color_number = ft_strlen(fractol->col.color_array);
	fractol->col.char_ppix = 1;
	fractol->img.mlx_img = NULL;
	fractol->img.endian = 0;
}
