#ifndef MINI_PAINT_H
# define MINI_PAINT_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_input
{
	int		w;
	int		h;
	char	back;
	char	*pic;
}	t_input;

typedef struct s_circle
{
	char	type;
	float	x;
	float	y;
	float	r;
	char	border;
	char	inside;
}	t_circle;

#endif