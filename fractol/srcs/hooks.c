/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:55:14 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/29 17:47:20 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
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
		printf("Key %d was pressed!\n", keycode);
	render(data);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
		data->set.zoom *= 1.1;
	else if (keycode == 5)
		data->set.zoom *= 0.9;
	data->set.pr = (x - WIDTH / 2) / (data->set.zoom * WIDTH)
		+ data->set.move_x;
	data->set.pi = (y - HEIGHT / 2) / (data->set.zoom * HEIGHT)
		+ data->set.move_y;
	data->set.move_x = data->set.pr;
	data->set.move_y = data->set.pi;
	render(data);
	return (0);
}
