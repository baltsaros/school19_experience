#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int		*ret;
	int		i;

	ret = (int *)malloc(length * sizeof(ret));
	i = 0;
	while (i < length)
	{
		ret[i] = (*f)(tab[i]);
		printf("tab[%d] --- ret[%d]\n", i, i);
		printf("  %d   ---  %d\n", tab[i], ret[i]);
		++i;
	}
	return (ret);
}

int	rest_ten(int n)
{
	n = n % 10;
	return (n);
}

int	main(void)
{
	int		tab[] = {11, 22, 73, 84, 95, 36, 47, 58, 69, 100};
	int		length;


	length = 10;
	ft_map(tab, length, &rest_ten);
	return (0);
}
