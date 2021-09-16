int		ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
	{
		while (power != 1)
		{
			nb = nb * n;
			--power;
		}
		return (nb);
	}
}

#include <stdio.h>
int		main()
{
	printf("%d\n", ft_iterative_power(3, -2));
	printf("%d\n", ft_iterative_power(3, 0));
	printf("%d\n", ft_iterative_power(3, 1));
	printf("%d\n", ft_iterative_power(3, 2));
	printf("%d\n", ft_iterative_power(3, 3));
	printf("%d\n", ft_iterative_power(3, 4));
	printf("%d\n", ft_iterative_power(3, 5));
	return (0);
}