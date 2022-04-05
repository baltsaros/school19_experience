/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:43:46 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/05 16:09:11 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_set
{
	double	pr;
	double	pi;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	double	zoom;
	double	move_x;
	double	move_y;
	int		color;
	int		iter;
}	t_set;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img	img;
	t_set	set;
	int		cur_img;
	int		setting[3];
	int		x;
	int		y;
}	t_data;

// errors
void	error_msg(void);
void	check_mlx(void *mlx);
void	check_win(t_data *data);
int		ft_exit(t_data *data);

// utils
int		ft_mini_atoi(const char *str);
int		encode_rgb(int i, int iter, int *setting);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

// hooks
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int keycode, int x, int y, t_data *data);
int	move_julia(int keycode, t_data *data);

// set initialization
void	init_mb(t_data *data);
void	init_julia(t_data *data);
void	init_newton(t_data *data);

// render
int		render_mandelbrot(t_data *data, t_img *img, t_set *mb, int *setting);
int		render_julia(t_data *data, t_img *img, t_set *jul, int *setting);
int		render_ship(t_data *data, t_img *img, t_set *ship, int *setting);

// fractol
int		render(t_data *data);
void	check_input(int argc, char *argv[], t_data *data);

#endif
