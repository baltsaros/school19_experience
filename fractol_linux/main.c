#include <stdio.h>
#include <stdlib.h>
#include "./mlx_linux/mlx.h"
#include <stdio.h>

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	t_img	img;
	int		cur_img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_set
{
	double	pr;
	double	pi;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	double	zoom;
	double	moveX;
	double	moveY;
	int		color;
	int		maxIter;
}	t_set;

typedef struct s_round
{
	int	x;
	int	y;
	int width;
	int height;
	int	radius;
	int color;
}	t_round;


enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	init_set(t_set *mb)
{
	mb->zoom = 1;
	mb->moveX = -0.5;
	mb->moveY = 0;
	mb->maxIter = 50;
	mb->color = 10000;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		exit(0);
	}
	else
		printf("Key %d was pressed!\n", keycode);
	return (0);
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

int	encode_rgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		i;

	i = img ->bpp - 8;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	// *(unsigned int*)dst = color;
	while (i >= 0)
	{
		if (img->endian != 0)
			*dst++ = (color >> i) & 0xFF;
		else
			*dst++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render_mandelbrot(t_img *img, t_set mb)
{
	int	x;
	int	y;
	int	i;
	int	iter;
	int	color;

	y = 0;
	iter = 200;
	color = 9999;
	while (y < 800)
	{
		x = 0;
		while (x < 900)
		{
			mb.pr = 1.5 * (x - 900 / 2) / (0.5 * mb.zoom * 900) + mb.moveX;
			mb.pi = (y - 800 / 2) / (0.5 * mb.zoom * 800) + mb.moveY;
			mb.newRe = mb.newIm = mb.oldRe = mb.oldIm = 0;
			i = 0;
			while (i < iter)
			{
				mb.oldRe = mb.newRe;
				mb.oldIm = mb.newIm;
				mb.newRe = mb.oldRe * mb.oldRe - mb.oldIm + mb.pr;
				mb.newIm = 2 * mb.oldRe * mb.oldIm + mb.pi;
				if ((mb.newRe * mb.newRe + mb.newIm * mb.newIm) > 4)
					break ;
				color += 250;
				my_mlx_pixel_put(img, x, y, color);
				++i;
			}
			++x;
		}
		++y;
	}
	return (0);
}

int	render_round(t_img *img, t_round round)
{
	int	i;
	int	j;

	i = round.y;
	while (i < round.y + round.height)
	{
		j = round.x;
		while (j < round.x + round.width)
			my_mlx_pixel_put(img, j++, i, round.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 800)
	{
		j = 0;
		while (j < 900)
			my_mlx_pixel_put(img, j++, i, color);
		++i;
	}
}

int	render(t_data *data)
{
	t_set	mandelbrot;

	if (data->win == NULL)
		return (1);
	render_background(&data->img, 0xFFFFFF);
	// render_rect(&data->img, (t_rect){0, 0, 100, 100, 0xFF00});
	// render_rect(&data->img, (t_rect){1720, 880, 200, 200, 0xFF0000});
	// render_rect(&data->img, (t_rect){500, 500, 200, 200, 203569230});
	// render_rect(&data->img, (t_rect){500, 500, 200, 200, 203569230});
	init_set(&mandelbrot);
	render_mandelbrot(&data->img, mandelbrot);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, 900, 800, "Test01");
	if (!data.win)
	{
		free(data.win);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx, 900, 800);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_length, &data.img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, 2, 3, key_hook, &data);
	// mlx_hook(data.win, 2, 17, exit_hook, &data);
	// mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_img, 0, 0);
	// my_mlx_pixel_put(&img, 10, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 9, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 8, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 7, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 6, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 5, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 4, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 3, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 2, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 1, 5, 0xFF00);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	// mlx_destroy_display(mlx);
	printf("01\n");
	free(data.mlx);
	return (0);
}