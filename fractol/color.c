#include <stdio.h>

int	encode_rgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

int	main(void)
{
	int	color;

	color = encode_rgb(12, 34, 56, 78);
	printf("TRGB is %d\n", color);
	return (0);
}