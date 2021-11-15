#include <stdio.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int		i;
	int		ret;
	int		increase;

	i = 0;
	increase = 1; 
	while (i < length - 1 && increase)
	{
		ret = (*f)(tab[i], tab[i + 1]);
		if (ret > 0)
			increase = 0;
		++i;
	}
	if (increase != 1)
	{
		while (i < length - 1)
		{
			ret = (*f)(tab[i], tab[i + 1]);
			if (ret < 0)
				return (0);
			++i;
		}
	}
	return (1);
}

int	ft_sort(int a, int b)
{
	if (a && b)
		return (a - b);
	else
		return (1);
}

int main(void)
{
	int		array[5] = {10, 1, 5, 1, 2};
	int		length;

	length = 5;
	printf("return is %d\n", ft_is_sort(array, length, &ft_sort));
	return (0);
}
