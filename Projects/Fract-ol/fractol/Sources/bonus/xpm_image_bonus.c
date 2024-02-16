/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:58:03 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:47:01 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fractol_bonus.h"

/**
 * * Create an image from a xpm file and put it in the window
 * @param: fractol structure
 * @return: 1 if success, 0 if error
 */
int	ft_xpm_image(t_fractol *fractol)
{
	int	width;
	int	height;

	fractol->img.mlx_img = \
	mlx_xpm_file_to_image(fractol->mlx, "fractal.xpm", &width, &height);
	if (fractol->img.mlx_img == NULL)
		return (ft_printf("Error reading xpm image\n"), 0);
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.mlx_img, 0, 0);
	return (1);
}

/**
 * * Fill header of xpm with tags
 * @param: width, height, color number, number of characters per pixel
 * @param: color palette
*/
static void	ft_fill_xpm_header(t_fractol fractol, int fd)
{
	ft_putstr_fd("/* XPM */\nstatic char *fractol[] = {\n", fd);
	ft_putstr_fd("\"", fd);
	ft_putnbr_fd(fractol.width, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(fractol.height, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(fractol.col.color_number, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(fractol.col.char_ppix, fd);
	ft_putstr_fd("\",\n", fd);
	ft_putstr_fd(fractol.col.color_palette, fd);
}

/**
 * * Create a xpm file (xpm3) from input and fill it with the fractal data
 * Open and/or create the file with the right permissions 
 * 0644:
 * 0(file: No special permission or type)
 * 6(owner:r and w)
 * 4(group: r)
 * 4(others: r))
 * @param: width, height, color number, number of characters per pixel
 * @param: color palette
 * @param: fractal data
 * @return: 1 if success, 0 if error
*/
int	ft_create_xpm(t_fractol *fractol)
{
	int	fd;
	int	i;
	int	j;

	fd = open("fractal.xpm", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (ft_printf("Error creating xpm file\n"), close(fd), (0));
	ft_fill_xpm_header(*fractol, fd);
	i = 0;
	j = 0;
	ft_putchar_fd('"', fd);
	while (i < fractol->fra.fractal_data_len)
	{
		if (j == fractol->width)
		{
			ft_putstr_fd("\",\n\"", fd);
			j = 0;
		}
		ft_putchar_fd(fractol->fra.fractal_data[i], fd);
		i++;
		j++;
	}
	ft_putstr_fd("\"\n};", fd);
	close(fd);
	return (1);
}
