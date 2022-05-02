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

int	draw_back(t_input *params)
{
	int		i;
	float	x;
	float	y;
	i = 0;
	y = 0.000000;
	while (y < params->h)
	{
		x = 0.000000;
		while (x < params->w)
		{
			params->pic[i] = params->back;
			++i;
			++x;
		}
		params->pic[i] = '\n';
		++i;
		++y;
	}
	params->pic[i] = '\0';
	return (0);
}

int	draw_front(t_input *params, t_rect *rect)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	y = 0.000000;
	while (y < params->h)
	{
		x = 0.000000;
		while (x < params->w)
		{
			if (rect->x <= x && rect->y <= y && x <= (rect->x + rect->w) && y <= (rect->y + rect->h))
			{
				params->pic[i] = rect->border;
				if (rect->x > x - 1 && rect->y > y - 1
					&& x + 1 > (rect->x + rect->w) && y + 1 > (rect->y + rect->h))
					params->pic[i] = rect->inside;
				// if (rect->type == 'R' && rect->x <= x - 1 && rect->y <= y - 1
				// 	&& x + 1 <= (rect->x + rect->w) && y + 1 <= (rect->y + rect->h))
				// 	params->pic[i] = rect->inside;
			}
			++i;
			++x;
		}
		++i;
		++y;
	}
	return (0);
}

int	data_init(FILE *stream)
{
	t_input	params;
	t_rect	rect;
	int		ret;
	int		i;

	i = 1;
	ret = fscanf(stream, "%d %d %c\n", &params.w, &params.h, &params.back);
	if (ret != 3 || !(params.w > 0 && params.w <= 300) || !(params.h > 0 && params.h <= 300) || !(params.back >= 32 && params.back <= 126))
	{
		printf("Error: wrong input\n");
		return (1);
	}
	params.pic = malloc(sizeof(char) * (params.h * params.w + params.h));
	if (!params.pic)
		return (1);
	draw_back(&params);
	ret = fscanf(stream, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.w, &rect.h, &rect.border);
	// while (ret == 6 && (rect.type == 'R' || rect.type == 'r') && rect.x > 0.000000 && rect.y > 0.000000 && (rect.border >= 26 && rect.border <= 126))
	while (ret == 6)
	{
		if (rect.type == 82)
			rect.inside = rect.border;
		else if (rect.type == 114)
			rect.inside = params.back;
		else
		{
			free(params.pic);
			printf("Error: wrong input\n");
			return (1);
		}
		if ((rect.type == 'R' || rect.type == 'r') && rect.w > 0.000000 && rect.h > 0.000000 && (rect.border >= 26 && rect.border <= 126))
		{
			draw_front(&params, &rect);
			printf("[%d]\n", i);
			++i;
		}
		ret = fscanf(stream, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.w, &rect.h, &rect.border);
	}
	printf("input: %d %d %c\n", params.w, params.h, params.back);
	printf("rect: %c %f %f %f %f %c %c\n", rect.type, rect.x, rect.y, rect.w, rect.h, rect.border, rect.inside);
	printf("%s", params.pic);
	free(params.pic);
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
