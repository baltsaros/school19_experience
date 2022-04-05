/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:55:14 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/05 16:11:16 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img.mlx_img);
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 123)
		data->set.move_x *= 1.1;
	else if (keycode == 124)
		data->set.move_x *= 0.9;
	else if (keycode == 125)
		data->set.move_y *= 1.1;
	else if (keycode == 126)
		data->set.move_y *= 0.9;
	else if (keycode == 24)
		data->set.zoom *= 1.5;
	else if (keycode == 27)
		data->set.zoom *= 0.9;
	else
		ft_printf("Key %d was pressed!\n", keycode);
	move_julia(keycode, data);
	render(data);
	return (0);
}

int	move_julia(int keycode, t_data *data)
{
	if (data->setting[0] != 2)
		return (0);
	if (keycode == 12)
	{
		data->set.pi -= 0.001; 
		data->set.pr -= 0.001; 
	}
	else if (keycode == 13)
	{
		data->set.pi += 0.001; 
		data->set.pr += 0.001; 
	}
	else if (keycode == 0)
	{
		data->set.pi -= 0.01; 
		data->set.pr -= 0.01; 
	}
	else if (keycode == 1)
	{
		data->set.pi += 0.01; 
		data->set.pr += 0.01; 
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
		data->set.zoom *= 1.1;
	else if (keycode == 5)
		data->set.zoom *= 0.9;
	data->set.move_x = (x - WIDTH / 2) / (data->set.zoom * WIDTH)
		+ data->set.move_x;
	data->set.move_y = (y - HEIGHT / 2) / (data->set.zoom * HEIGHT)
		+ data->set.move_y;
	render(data);
	return (0);
}
