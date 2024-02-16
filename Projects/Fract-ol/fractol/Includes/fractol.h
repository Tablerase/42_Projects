/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:08:30 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/18 00:42:32 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// MiniLibX library
# include "../mlx/mlx.h"
// Libft library
# include "../libft/Includes/libft.h"
// color
# include "color.h"

// Keyboard keys library / X11 events
# include <X11/keysym.h>
# include <X11/X.h>
// Math library
# include <math.h>

// Window size
# define WIDTH 800
# define HEIGHT 800

// Structures

// Image structure
// endianness: little(0) or big endian(1) (depends on the system)
typedef struct s_img
{
	void	*mlx_img;
	int		endian;
}	t_img;

// Color structure
// color_mode: escape_time, normalize_iter_count
// char_ppix: number of characters per pixel
typedef struct s_color
{
	char	*color_mode;
	char	*palette_name;
	char	*color_palette;
	char	*color_array;
	int		color_number;
	int		char_ppix;
}	t_color;

// Fractal structure
// fractal: mandelbrot, julia, burningship
typedef struct s_fractal
{
	char	*fractal_type;
	char	*fractal_data;
	int		fractal_data_len;
	int		max_iterations;
	double	zoom;
	double	x;
	double	y;
	double	c_real;
	double	c_imaginary;
	int		mouse_x;
	int		mouse_y;
	double	param_storage;
}	t_fractal;

// Fractol structure
typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_img		img;
	t_fractal	fra;
	t_color		col;
}	t_fractol;

void	ft_fill_structure(t_fractol *fractol);

//Fractal functions
void	ft_check_julia_args(char **argv, t_fractol *fractol);
void	ft_fill_julia(t_fractol *fractol);
double	ft_atof(const char *str);
void	ft_fractal(t_fractol *fractol);
void	ft_mandelbrot(t_fractol *fractol);
void	ft_julia(t_fractol *fractol);

// Manage mlx and window
int		ft_create_window(t_fractol *fractol);
int		ft_xpm_image(t_fractol *fractol);
int		ft_create_xpm(t_fractol *fractol);

// Infos
void	ft_infos(t_fractol *fractol);
int		ft_display_mouse_pos(int mouse_x, int mouse_y, t_fractol *fractol);
void	ft_infos_mouse_position(t_fractol *fractol);
void	ft_args_error(void);

// Free memory and exit program
int		ft_exit(t_fractol *fractol);

// Key/Mouse hooks
int		ft_keyhooks(int keycode, t_fractol *fractol);
int		ft_mouse_hooks(int button, int x, int y, t_fractol *fractol);

// Color algorithms
int		ft_colormode(int iterations, t_fractol *fractal);

#endif