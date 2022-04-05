/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:57:45 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/05 16:22:33 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_mb(t_data *data)
{
	data->set.zoom = 0.1;
	data->set.move_x = 0.1;
	data->set.move_y = 0.1;
}

void	init_julia(t_data *data)
{
	data->set.zoom = 0.1;
	data->set.move_x = 0.1;
	data->set.move_y = 0.1;
	if (data->setting[2] == 1)
	{
		data->set.pr = -0.7;
		data->set.pi = 0.27;
	}
	else if (data->setting[2] == 2)
	{
		data->set.pr = -0.7;
		data->set.pi = 0.32;
	}
	else if (data->setting[2] == 3)
	{
		data->set.pr = -0.778;
		data->set.pi = -0.116;
	}
}

void	init_newton(t_data *data)
{
	data->set.zoom = 0.1;
	data->set.move_x = 0.1;
	data->set.move_y = 0.1;
	data->set.color = 251231;
	if (data->setting[2] == 1)
	{
		data->set.pr = -0.7;
		data->set.pi = 0.27;
	}
	else if (data->setting[2] == 2)
	{
		data->set.pr = -0.7;
		data->set.pi = 0.32;
	}
	else if (data->setting[2] == 3)
	{
		data->set.pr = -0.77;
		data->set.pi = -0.08;
	}
}
