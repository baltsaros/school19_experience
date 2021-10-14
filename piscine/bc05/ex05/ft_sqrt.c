int	ft_sqrt(int nb)
{
	int		i;
	int		square;

	i = 1;
	if (nb > 2)
	{
		while (i < 46341)
		{
			square = i * i;
			if (nb == square)
				return (i);
			if (nb < square)
				return (0);
			++i;
		}
	}
	if (nb == 1)
		return (1);
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
	printf("%d\n", ft_sqrt(2147395600));
}