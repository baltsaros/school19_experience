#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct	s_img
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
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	double	zoom;
	double	moveX;
	double	moveY;
	int		color;
	int		iter;
}	t_set;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	t_img	img;
	t_set	mb;
	int		cur_img;
	int		iter;
}	t_data;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	init_set(t_data *data)
{
	data->mb.zoom = 0.1;
	data->mb.moveX = 0.1;
	data->mb.moveY = 0.1;
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

int	render_mandelbrot(t_img *img, t_set *mb)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	mb->iter = 30;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mb->pr = (x - WIDTH / 2) / (mb->zoom * WIDTH) + mb->moveX;
			mb->pi = (y - HEIGHT / 2) / (mb->zoom * HEIGHT) + mb->moveY;
			mb->newRe = mb->newIm = mb->oldRe = mb->oldIm = 0;
			i = 0;
			while (i < mb->iter)
			{
				mb->oldRe = mb->newRe;
				mb->oldIm = mb->newIm;
				mb->newRe = mb->oldRe * mb->oldRe - mb->oldIm * mb->oldIm + mb->pr;
				mb->newIm = 2 * mb->oldRe * mb->oldIm + mb->pi;
				// color = encode_rgb((1499 + i) % 256, 155, 200 * (i < iter));
				mb->color = encode_rgb((1433 + i) % 250, 190 - i, 80 * (i < mb->iter));
				if ((mb->newRe * mb->newRe + mb->newIm * mb->newIm) > 4)
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
	render_mandelbrot(&data->img, &data->mb);
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
		data->mb.moveX *= 1.1;
	else if (keycode == 124)
		data->mb.moveX *= 0.9;
	else if (keycode == 125)
		data->mb.moveY *= 1.1;
	else if (keycode == 126)
		data->mb.moveY *= 0.9;
	else if (keycode == 24)
		data->mb.zoom *= 1.5;
	else if (keycode == 27)
		data->mb.zoom *= 0.9;
	else
		printf("Key %d was pressed!\n", keycode);
	render(data);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
		data->mb.zoom *= 1.1;
	else if (keycode == 5)
		data->mb.zoom *= 0.9;
	data->mb.pr = (x - WIDTH / 2) / (data->mb.zoom * WIDTH) + data->mb.moveX;
	data->mb.pi = (y - HEIGHT / 2) / (data->mb.zoom * HEIGHT) + data->mb.moveY;
	data->mb.moveX = data->mb.pr;
	data->mb.moveY = data->mb.pi;
	render(data);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Test01");
	if (!data.win)
	{
		free(data.win);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_length, &data.img.endian);
	init_set(&data);
	data.iter = 1;
	// mlx_loop_hook(data.mlx, &render, &data);
	// mlx_hook(data.win, 2, 3, mlx_key_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	// mlx_hook(data.win, 2, 17, exit_hook, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_img, 0, 0);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	// mlx_destroy_display(mlx);
	free(data.mlx);
	return (0);
}
