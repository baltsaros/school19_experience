#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>

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
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	double	zoom;
	double	move_x;
	double	move_y;
	int		color;
	int		iter;
	double	c_re;
	double	c_im;
}	t_set;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	t_img	img;
	t_set	set;
	int		cur_img;
	int		setting[3];
}	t_data;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_mini_atoi(const char *str);
int		encode_rgb(int i, int iter, int *setting);

#endif
