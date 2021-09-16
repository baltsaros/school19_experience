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
	printf("%d\n", ft_iterative_factorial(3));
	return 0;
}
