int		ft_recursieve_power(int nb, int power)
{
	int	n;

	if (power > 0)
	{
		--power;
		n = nb * ft_recursieve_power(nb, power);
		return (n);
	}
	if (power == 0)
		return (1);
	else
		return (0);
		
}

#include <stdio.h>
int		main()
{
	printf("%d\n", ft_recursieve_power(3, -2));
	printf("%d\n", ft_recursieve_power(3, 0));
	printf("%d\n", ft_recursieve_power(3, 1));
	printf("%d\n", ft_recursieve_power(3, 2));
	printf("%d\n", ft_recursieve_power(3, 3));
	printf("%d\n", ft_recursieve_power(3, 4));
	printf("%d\n", ft_recursieve_power(3, 5));
	return (0);
}