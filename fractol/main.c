#include <stdlib.h>
#include <mlx.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Test01");
	if (!mlx_win)
	{
		free(mlx_win);
		return (1);
	}
	img.img = mlx_new_image(mlx, 1920, 1080);
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
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	// mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}