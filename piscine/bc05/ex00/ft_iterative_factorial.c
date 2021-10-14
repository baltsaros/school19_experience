int	ft_iterative_factorial(int nb)
{
	int		f;

	f = 1;
	if (nb == 0 || nb == 1)
		return (1);
	if (nb > 1)
	{
		while(nb != 1)
		{
			f = f * nb;
			--nb;
		}
		return (f);
	}
	else
		return (0);
}

#include <stdio.h>
int	main()
{
	printf("%d\n", ft_iterative_factorial(-2));
	printf("%d\n", ft_iterative_factorial(0));
	printf("%d\n", ft_iterative_factorial(1));
	printf("%d\n", ft_iterative_factorial(2));
	printf("%d\n", ft_iterative_factorial(3));
	printf("%d\n", ft_iterative_factorial(4));
	printf("%d\n", ft_iterative_factorial(5));
	printf("%d\n", ft_iterative_factorial(6));
	return 0;
}
