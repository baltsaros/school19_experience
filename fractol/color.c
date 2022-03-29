#include "fractol.h"

int	encode_rgb(int i, int iter, int *setting)
{
	if (setting[1] == 1)
		return (((1433 + i) % 250) << 16 | (190 - i) << 8 | 80 * (i < iter));
	else if (setting[1] == 2)
		return (((1499 + i) % 256) << 16 | (155 - i) << 8 | 200 * (i < iter));
	else if (setting[1] == 3)
		return (((133 + i) % 150) << 16 | (235 - i) << 8 | 170 * (i < iter));
	else
		exit(EXIT_FAILURE);
}
