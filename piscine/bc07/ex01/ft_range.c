#include <stdlib.h> 

int	*ft_range(int min, int max)
{
	int		size;
	int		*tab;
	int		i;

	if (min >= max)
		return (NULL);
	size = max - min;
	tab = (int *)malloc(sizeof(*tab) * size);
	if (NULL == tab)
		return (NULL);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		++min;
		++i;
	}
	return (tab);
}

#include <stdio.h>
int	main()
{
	int		*tab;
	int		j;
	
	tab = ft_range(1, 5);
	j = 0;
	while (j < 4) // less than (max - min) otherwise seg fault
	{
		printf("%d ", tab[j]);
		++j;
	}
	return (0);
}