#include "mini_paint.h"

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
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (y < params->h)
	{
		x = 0;
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

int	draw_front(t_input *params, t_circle *circle)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < params->h)
	{
		x = 0;
		while (x < params->w)
		{
			if (sqrtf(powf(x - circle->x, 2) + powf(y - circle->y, 2)) <= circle->r)
			{
				if (circle->r - sqrtf(powf(x - circle->x, 2) + powf(y - circle->y, 2)) < 1)
					params->pic[i] = circle->border;
				else if (circle->type == 'C')
					params->pic[i] = circle->border;
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
	t_input		params;
	t_circle	circle;
	int			ret;

	ret = fscanf(stream, "%d %d %c\n", &params.w, &params.h, &params.back);
	if (ret != 3 || !(params.w > 0 && params.w <= 300) || !(params.h > 0
		&& params.h <= 300) || !(params.back >= 32 && params.back <= 126))
	{
		error_msg(2);
		return (1);
	}
	params.pic = malloc(sizeof(char) * (params.w * params.h + params.h));
	if (!params.pic)
		return (1);
	draw_back(&params);
	ret = fscanf(stream, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y,
		&circle.r, &circle.border);
	while (ret == 5)
	{
		if (circle.r > 0.000000 && (circle.type == 'c' || circle.type == 'C') 
			&& (circle.border >= 32 && circle.border <= 126))
			draw_front(&params, &circle);
		ret = fscanf(stream, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y,
			&circle.r, &circle.border);
	}
	printf("input: %d %d %c\n", params.w, params.h, params.back);
	printf("circle: %c %f %f %f %c\n", circle.type, circle.x, circle.y
		, circle.r, circle.border);
	printf("%s", params.pic);
	free(params.pic);
	return (0);
}

int	main(int argc, char *argv[])
{
	FILE	*path;
	int		i;

	if (argc != 2)
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
	data_init(path);
	fclose(path);
	return (0);
}
