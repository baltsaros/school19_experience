/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:30:50 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/06 12:45:01 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	render(t_data *data)
{
	check_win(data);
	data->y = 0;
	data->set.iter = 450;
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			if (data->setting[0] == 1)
				render_mandelbrot(data, &data->img, &data->set, data->setting);
			else if (data->setting[0] == 2)
				render_julia(data, &data->img, &data->set, data->setting);
			else if (data->setting[0] == 3)
				render_ship(data, &data->img, &data->set, data->setting);
			++data->x;
		}
		++data->y;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}

void	check_input(int argc, char *argv[], t_data *data)
{
	if (argc < 3 || argc > 4)
		error_msg();
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		data->setting[0] = 1;
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
		data->setting[0] = 2;
	else if (ft_strncmp(argv[1], "Ship", 5) == 0)
		data->setting[0] = 3;
	else
		data->setting[0] = -1;
	data->setting[1] = ft_mini_atoi(argv[2]);
	data->setting[2] = 0;
	if (argc == 3 && data->setting[0] == 2)
		error_msg();
	if (data->setting[0] == 2)
		data->setting[2] = ft_mini_atoi(argv[3]);
	if (data->setting[0] < 0 || data->setting[1] < 0 || data->setting[2] < 0)
		error_msg();
}

int	main(int argc, char *argv[])
{
	t_data	data;

	check_input(argc, argv, &data);
	data.mlx = mlx_init();
	check_mlx(data.mlx);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, argv[1]);
	check_win(&data);
	data.img.mlx_img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_length, &data.img.endian);
	if (data.setting[0] == 1 || data.setting[0] == 3)
		init_mb(&data);
	else if (data.setting[0] == 2)
		init_julia(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, ft_exit, &data);
	mlx_loop(data.mlx);
	return (0);
}
