#include <stdio.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int		i;

	i = 0;
	while (i < length)
	{
		printf("tab[%d] is %d, changed tab[%d] is ", i, tab[i], i);
		(*f)(tab[i]);
		++i;
	}
}

void	num_plus_one(int n)
{
	n = n + 1;
	printf("%d\n", n);
}

int		main(void)
{
	int		tab[] = {1, 2, 3, 4, 5};
	int		length;

	length = 5;
	ft_foreach(tab, length, &num_plus_one);
	return (0);
}
