/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:13:02 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/06 12:38:41 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	render_mandelbrot(t_data *data, t_img *img, t_set *mb, int *setting)
{
	int	i;

	mb->pr = (data->x - WIDTH / 2) / (mb->zoom * WIDTH) + mb->move_x;
	mb->pi = (data->y - HEIGHT / 2) / (mb->zoom * HEIGHT) + mb->move_y;
	mb->new_re = 0;
	mb->new_im = 0;
	i = 0;
	while ((mb->new_re * mb->new_re + mb->new_im * mb->new_im)
		<= 4 && i < mb->iter)
	{
		mb->old_re = mb->new_re;
		mb->old_im = mb->new_im;
		mb->new_re = mb->old_re * mb->old_re - mb->old_im * mb->old_im + mb->pr;
		mb->new_im = 2 * mb->old_re * mb->old_im + mb->pi;
		mb->color = encode_rgb(i, mb->iter, setting);
		my_mlx_pixel_put(img, data->x, data->y, mb->color);
		++i;
	}
	return (0);
}

int	render_julia(t_data *data, t_img *img, t_set *jul, int *setting)
{
	int	i;

	jul->new_re = (data->x - WIDTH / 2) / (jul->zoom * WIDTH) + jul->move_x;
	jul->new_im = (data->y - HEIGHT / 2) / (jul->zoom * HEIGHT) + jul->move_y;
	i = 0;
	while (i < jul->iter)
	{
		jul->old_re = jul->new_re;
		jul->old_im = jul->new_im;
		jul->new_re = jul->old_re * jul->old_re - jul->old_im
			* jul->old_im + jul->pr;
		jul->new_im = 2 * jul->old_re * jul->old_im + jul->pi;
		jul->color = encode_rgb(i, jul->iter, setting);
		if ((jul->new_re * jul->new_re + jul->new_im * jul->new_im) > 4)
		{
			my_mlx_pixel_put(img, data->x, data->y, jul->color);
			break ;
		}
		my_mlx_pixel_put(img, data->x, data->y, jul->color);
		++i;
	}
	return (0);
}

int	render_ship(t_data *data, t_img *img, t_set *ship, int *setting)
{
	int	i;

	ship->pr = (data->x - WIDTH / 2) / (ship->zoom * WIDTH) + ship->move_x;
	ship->pi = (data->y - HEIGHT / 2) / (ship->zoom * HEIGHT) + ship->move_y;
	ship->new_re = 0;
	ship->new_im = 0;
	i = 0;
	while ((ship->new_re * ship->new_re + ship->new_im * ship->new_im)
		<= 4 && i < ship->iter)
	{
		ship->old_re = ship->new_re;
		ship->old_im = ship->new_im;
		ship->new_re = ship->old_re * ship->old_re - ship->old_im
			* ship->old_im + ship->pr;
		ship->new_im = 2 * fabs(ship->old_re * ship->old_im) + ship->pi;
		ship->color = encode_rgb(i, ship->iter, setting);
		my_mlx_pixel_put(img, data->x, data->y, ship->color);
		++i;
	}
	return (0);
}
