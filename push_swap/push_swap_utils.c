#include "push_swap.h"

void	error_msg()
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}

int		*ft_array_dup(int *old, int *new, int length)
{
	int	i;

	if (!old)
		return (0);
	i = 0;
	while (i < length)
	{
		new[i] = old[i];
		++i;
	}
	return (new);
}
