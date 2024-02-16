/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:12:55 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:36:00 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fractol.h"

/**
 * * Escape time algorithm
 * Give a color to a pixel depending on the number of iterations
 * Use an index(fraction of iterations) to calculate the color of the pixel
 * @param:  the number of iterations before the point diverge
 * @return: the color of the pixel
*/
static int	ft_escape_time(int iterations, t_fractol *fractol)
{
	double	index;

	if (iterations >= fractol->col.color_number)
		index = fractol->col.color_number - 1;
	else
		index = iterations;
	return (index);
}

/**
 * ! Not working like the real algorithm
 * * Normalize iteration count algorithm
 * Give a color to a pixel depending on the number of iterations
 * Use an index(fraction of iterations) to calculate the color of the pixel
 * @param:  the number of iterations before the point diverge
 * @return: the color of the pixel
*/
static int	ft_normalize_iter_count(int iterations, t_fractol *fractol)
{
	double	index;

	if (iterations >= fractol->col.color_number)
		index = fractol->col.color_number - 2;
	else
		index = iterations + 1;
	return (index);
}

/**
 * * Transform the color of a pixel depending on the color mode
 * @param:  the number of iterations before the point diverge
 * @param:  the color mode
 * @return: the color of the pixel
*/
int	ft_colormode(int iterations, t_fractol *fractol)
{
	if (ft_strncmp(fractol->col.color_mode, "escape_time", 12) == 0)
		return (ft_escape_time(iterations, fractol));
	if (ft_strncmp(fractol->col.color_mode, "normalize_iter_count", 21) == 0)
		return (ft_normalize_iter_count(iterations, fractol));
	return (0);
}
