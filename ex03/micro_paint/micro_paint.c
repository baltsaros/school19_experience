#include "micro_paint.h"

typedef struct s_input
{
	int		w;
	int		h;
	char	back;
} 	t_input;

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	w;
	float	h;
	char	border;
	char	inside;
}	t_rect;

void	error_msg(int num)
{
	if (num == 0)
		write(1, "Error: argument\n", 16);
	else if (num == 1)
		write (1, "Error: Operation file corrupted\n", 32);
	else if (num == 2)
		write (1, "Error: invalid line\n", 20);
}

int	data_init(FILE *stream)
{
	t_input	params;
	t_rect	rect;
	int		ret;

	ret = fscanf(stream, "%d %d %c\n", &params.w, &params.h, &params.back);
	if (ret != 3 || !(params.w > 0 && params.w <= 300) || !(params.h > 0 && params.h <= 300) || !(params.back >= 32 && params.back <= 126))
	{
		printf("Error: wrong input\n");
		return (1);
	}
	ret = fscanf(stream, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.w, &rect.h, &rect.border);
	if (ret != 6 || (rect.type != 'R' && rect.type != 'r') || rect.x <= 0.000000 || rect.y <= 0.000000 || rect.border < 26 || rect.border > 126)
	{
		printf("Second\n");
		printf("Error: wrong input\n");
		return (1);
	}
	if (rect.type == 82)
		rect.inside = rect.border;
	else if (rect.type == 114)
		rect.inside = params.back;
	else
		return (1);
	printf("input: %d %d %c\n", params.w, params.h, params.back);
	printf("rect: %c %f %f %f %f %c %c\n", rect.type, rect.x, rect.y, rect.w, rect.h, rect.border, rect.inside);
	return (0);
}

int	main(int argc, char *argv[])
{
	FILE	*path;
	int		i;

	printf("start\n");
	if (argc <= 1 || argc > 2)
	{
		error_msg(0);
		return (1);
	}
	path = fopen(argv[1], "r");
	if (!path)
	{
		error_msg(1);
		return (1);
	}
	printf("data_init\n");
	data_init(path);
	return (0);
}