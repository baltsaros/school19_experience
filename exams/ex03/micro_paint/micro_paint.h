#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

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

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	w;
	float	h;
	char	border;
}	t_rect;

#endif