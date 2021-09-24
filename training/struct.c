#include <stdio.h>

struct s_point
{
	int		x;
	int		y;
	char	*str;
};

int	main(void)
{
	struct s_point	tab[3];

	tab[0].x = 21;
	tab->y = 7;
	tab[2].str = "hello";
	printf("x %d\ny %d\nstr %s\n", tab->x, tab[1].y, tab[2].str);
	printf("str %s\nstr %s\nstr %s\n", tab->str, tab[0].str, tab[1].str);
	printf("y %d\ny %d\ny %d\n", tab->y, tab[1].y, tab[0].y);
	printf("size x %lu\ny %lu\nstr %lu\n%lu\n", sizeof(tab[1].x), sizeof(tab[0].y), sizeof(tab[1].str), sizeof(tab[2].str));
	printf("size of str %lu\n", sizeof(tab));
}