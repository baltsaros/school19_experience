#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int		main()
{
	int		nbr;

	nbr = 40;
	ft_ft(&nbr);
	printf("%d\n", nbr);
	return (0);
}
