#include "micro_paint.h"

void	error_msg(int num)
{
	if (num == 0)
		write(1, "Error: argument\n", 16);
	else if (num == 1)
		write (1, "Error: Operation file corrupted\n", 32);
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
				if (x - rect->x < 1.000000 || (rect->x + rect->w) - x < 1.000000
					|| y - rect->y < 1.000000 || (rect->y + rect->h) - y < 1.000000)
					params->pic[i] = rect->border;
				else if (rect->type == 'R')
					params->pic[i] = rect->border;
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
	
	ret = fscanf(stream, "%d %d %c\n", &params.w, &params.h, &params.back);
	if (ret != 3 || !(params.w > 0 && params.w <= 300) || !(params.h > 0
		&& params.h <= 300) || !(params.back >= 32 && params.back <= 126))
	{
		error_msg(1);
		return (1);
	}
	params.pic = malloc(sizeof(char) * (params.h * params.w + params.h));
	if (!params.pic)
	{
		error_msg(1);
		return (1);
	}
	draw_back(&params);
	ret = fscanf(stream, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.w
		, &rect.h, &rect.border);
	while (ret == 6)
	{
		if ((rect.type == 'R' || rect.type == 'r') && rect.w > 0.000000 && rect.h > 0.000000
			&& (rect.border >= 32 && rect.border <= 126))
			draw_front(&params, &rect);
		else
		{
			free(params.pic);
			error_msg(1);
			return (1);
		}
		ret = fscanf(stream, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.w
			, &rect.h, &rect.border);
	}
	if (ret != 6 && ret != EOF)
	{
		free(params.pic);
		error_msg(1);
		return (1);
	}
	// printf("input: %d %d %c\n", params.w, params.h, params.back);
	// printf("rect: %c %f %f %f %f %c\n", rect.type, rect.x, rect.y, rect.w, rect.h, rect.border);
	// printf("%s", params.pic);
	write(1, params.pic, params.h * params.w + params.h);
	free(params.pic);
	return (0);
}

int	main(int argc, char *argv[])
{
	FILE	*path;

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
	if (data_init(path))
	{
		fclose(path);
		return (1);
	}
	fclose(path);
	return (0);
}
