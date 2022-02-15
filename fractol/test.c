#include <stdlib.h>
#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == EX_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	else
		printf("Key was pressed!\n");
	return (0);
}

int	encode_rgb(uint8_t red, uint8_t gree, uint8_t blue)
{
	return (red << 16 | gree << 8 | blue);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Test01");
	if (!vars.win)
	{
		free(vars.win);
		return (1);
	}
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 10, 5, 0xFF00);
	my_mlx_pixel_put(&img, 9, 5, 0xFF00);
	my_mlx_pixel_put(&img, 8, 5, 0xFF00);
	my_mlx_pixel_put(&img, 7, 5, 0xFF00);
	my_mlx_pixel_put(&img, 6, 5, 0xFF00);
	my_mlx_pixel_put(&img, 5, 5, 0xFF00);
	my_mlx_pixel_put(&img, 4, 5, 0xFF00);
	my_mlx_pixel_put(&img, 3, 5, 0xFF00);
	my_mlx_pixel_put(&img, 2, 5, 0xFF00);
	my_mlx_pixel_put(&img, 1, 5, 0xFF00);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	// mlx_destroy_display(mlx);
	free(vars.mlx);
	return (0);
}