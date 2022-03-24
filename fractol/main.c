#include "fractol.h"

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
	data->set.color = 251231;
	data->set.c_re = -0.743;
	data->set.c_im = 0.32;
}

// int	exit_hook(int keycode, t_data *data)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(data->mlx, data->win);
// 		data->win = NULL;
// 		exit(0);

// 	}
// 	else
// 		printf("Key %d was pressed!\n", keycode);
// 	return (0);
// }

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	encode_trgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		i;

	i = img ->bpp - 8;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
	while (i >= 0)
	{
		if (img->endian != 0)
			*dst++ = (color >> i) & 0xFF;
		else
			*dst++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render_julia(t_img *img, t_set *jul)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	jul->iter = 150;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			jul->new_re = (x - WIDTH / 2) / (jul->zoom * WIDTH) + jul->move_x;
			jul->new_im = (y - HEIGHT / 2) / (jul->zoom * HEIGHT) + jul->move_y;
			i = 0;
			while (i < jul->iter)
			{
				jul->old_re = jul->new_re;
				jul->old_im = jul->new_im;
				jul->new_re = jul->old_re * jul->old_re - jul->old_im * jul->old_im + jul->c_re;
				jul->new_im = 2 * jul->old_re * jul->old_im + jul->c_im;
				// color = encode_rgb((1499 + i) % 256, 155, 200 * (i < iter));
				jul->color = encode_rgb((1433 + i) % 250, 190 - i, 80 * (i < jul->iter));
				if ((jul->new_re * jul->new_re + jul->new_im * jul->new_im) > 4)
				{
					my_mlx_pixel_put(img, x, y, jul->color);
					break ;
				}
				// my_mlx_pixel_put(img, x, y, 0xFF);
				// my_mlx_pixel_put(img, x, y, jul->color);
				++i;
			}
			++x;
		}
		++y;
	}
	return (0);
}

int	render_mandelbrot(t_img *img, t_set *mb)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	mb->iter = 50;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mb->pr = (x - WIDTH / 2) / (mb->zoom * WIDTH) + mb->move_x;
			mb->pi = (y - HEIGHT / 2) / (mb->zoom * HEIGHT) + mb->move_y;
			mb->new_re = mb->new_im = mb->old_re = mb->old_im = 0;
			i = 0;
			while (i < mb->iter)
			{
				mb->old_re = mb->new_re;
				mb->old_im = mb->new_im;
				mb->new_re = mb->old_re * mb->old_re - mb->old_im * mb->old_im + mb->pr;
				mb->new_im = 2 * mb->old_re * mb->old_im + mb->pi;
				// color = encode_rgb((1499 + i) % 256, 155, 200 * (i < iter));
				mb->color = encode_rgb((1433 + i) % 250, 190 - i, 80 * (i < mb->iter));
				if ((mb->new_re * mb->new_re + mb->new_im * mb->new_im) > 4)
				{
					my_mlx_pixel_put(img, x, y, mb->color);
					break ;
				}
				// my_mlx_pixel_put(img, x, y, 0xF);
				my_mlx_pixel_put(img, x, y, mb->color);
				++i;
			}
			++x;
		}
		++y;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			my_mlx_pixel_put(img, j++, i, color);
		++i;
	}
}

int	render(t_data *data)
{

	if (data->win == NULL)
		return (1);
	// render_background(&data->img, 0xFFFFFF);
	
	if (data->setting[0] == 1)
		render_mandelbrot(&data->img, &data->set);
	else if (data->setting[0] == 2)
		render_julia(&data->img, &data->set);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		exit(0);
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
	data->set.pr = (x - WIDTH / 2) / (data->set.zoom * WIDTH) + data->set.move_x;
	data->set.pi = (y - HEIGHT / 2) / (data->set.zoom * HEIGHT) + data->set.move_y;
	data->set.move_x = data->set.pr;
	data->set.move_y = data->set.pi;
	render(data);
	return (0);
}

void	error_msg(void)
{
	printf("Invalid parameter(s)!\nThe porgram should be execution in the following way:\n");
	printf("./fractol <fractal set> <color set> <constant set>\n");
	printf("<fractal set> values: Mandelbrot, Julia, Newton\n");
	printf("<color set> values: 1, 2, 3\n");
	printf("<constant set> is only used for Julia set. It can be: 1, 2 3\n");
	printf("Please, try again\n");
	exit(EXIT_FAILURE);
}

void	check_input(char *argv[], t_data *data)
{
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		data->setting[0] = 1;
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
		data->setting[0] = 2;
	else if (ft_strncmp(argv[1], "Newton", 7) == 0)
		data->setting[0] = 3;
	else
		data->setting[0] = -1;
	data->setting[1] = ft_mini_atoi(argv[2]);
	data->setting[2] = 0;
	if (data->setting[0] == 2)
		data->setting[2] = ft_mini_atoi(argv[3]);
	printf("setting: %d | %d | %d \n", data->setting[0], data->setting[1], data->setting[2]);
	if (data->setting[0] < 0 || data->setting[1] < 0 || data->setting[2] < 0)
		error_msg();
}

int	main(int argc, char *argv[])
{
	t_data	data;

	printf("argc is %d\n", argc);
	if (argc < 3 || argc > 4)
		error_msg();
	check_input(argv, &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	if (!data.win)
	{
		free(data.win);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_length, &data.img.endian);
	if (data.setting[0] == 1)
		init_mb(&data);
	else if (data.setting[0] == 2)
		init_julia(&data);
	// mlx_loop_hook(data.mlx, &render, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_img, 0, 0);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	// mlx_destroy_display(mlx);
	free(data.mlx);
	return (0);
}
