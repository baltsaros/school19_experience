#include <stdlib.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	int		size;
	int		i;

	if (min >= max)
		{
			*range = NULL;
			return (0);
		}
	size = max - min;
	*range = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		++min;
		++i;
	}
	return (i);
}

#include <stdio.h>
int	main()
{
	int		*range;
	int		ret;

	ret = ft_ultimate_range(&range, 1, 5);
	printf("return is %d\n", ret);
	return (0);
}