#include "micro_paint.h"

void	error_msg(int num)
{
	if (num == 0)
		write(1, "Error: argument\n", 16);
	else if (num == 1)
		write (1, "Error: Operation file corrupted\n", 32);
	else if (num == 2)
		write (1, "Error: invalid line\n", 20);
}

int	draw(t_input *params, t_rect *rect)
{
	int		i;
	float	x;
	float	y;
	char *pic;

	pic = malloc(sizeof(pic) * (params->h * params->w + 1));
	if (!pic)
		return (1);
	i = 0;
	y = 0.000000;
	while (y < params->h)
	{
		x = 0.000000;
		while (x < params->w)
		{
			if (rect->x <= x && rect->y <= y && x <= (rect->x + rect->w) && y <= (rect->y + rect->h))
			{
				pic[i] = rect->inside;
				if ((x >= rect->x && (y == rect->y || y == rect->y + rect->h))
					|| (y >= rect->y && (x == rect->x || x == rect->x + rect->w)))
					pic[i] = rect->border;
			}
			else
				pic[i] = params->back;
			++i;
			printf("x is %f\n", x);
			++x;
		}
		pic[i] = '\n';
		++i;
		++y;
	}
	printf("y is %f\n", y);
	printf("%s", pic);
	free(pic);
	return (0);
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
	draw(&params, &rect);
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
