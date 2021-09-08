#include <stdio.h>

void	ft_ft(int nbr)
{
	int		*ptr;

	ptr = &nbr;
	printf("%d\n", *ptr);
}

int main()
{
	ft_ft(42);
	return 0;
}
