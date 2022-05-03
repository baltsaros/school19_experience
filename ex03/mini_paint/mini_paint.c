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

}

int	draw_front(t_input *params, t_circle *circle)
{

}

int	data_init(FILE *stream)
{
	t_input		params;
	t_circle	circle;
	int			ret;

	ret = fscanf("%d %d %c\n", &params.w, &params.h, &params.back);
	if (ret != 3)
	{
		error_msg(2);
		return (1);
	}
	params.pic = malloc(sizeof(char) * (params.w * params.h + params.h));
	if (!params.pic)
		return (1);
	ret = fscanf("%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.r, &circle.border);
	while (ret == 6)
	{
		
	}
}

int	main(int argc, char *argv[])
{
	FILE	*path;
	int		i;

	printf("start");
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
	return (0);
}