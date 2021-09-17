int	ft_recursive_power(int n, int power)
{
	int	i;

	if (power > 0)
	{
		--power;
		i = n * ft_recursive_power(n, power);
		return (i);
	}
	if (power == 0)
		return (1);
	else
		return (0);		
}

int	ft_sqrt(int nb)
{
	int	n;
	int	i;

	i = 1;
	if (nb == 1)
		return (1);
	while (i < nb)
	{
		if (nb == ft_recursive_power(i, 2))
			return (i);
		++i;
	}
	if (nb == 2)
		return (0);
	else
		return (0);
}

#include <stdio.h>
int	main()
{
	printf("%d\n", ft_sqrt(-2));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(5));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(25));
}