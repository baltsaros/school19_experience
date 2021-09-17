int	ft_recursive_factorial(int nb)
{
	int		f;

	f = 1;
	if (nb < 0)
		return(0);
	if (nb == 0 || nb == 1)
		return (1);
	while (nb % f == 0)
	{
		nb = nb / f;
		++f;
	}
	if (nb == 1)
		return (f - 1);
	else
		return (0);
}

#include <stdio.h>
int	main()
{
	printf("%d\n", ft_recursive_factorial(-1));
	printf("%d\n", ft_recursive_factorial(0));
	printf("%d\n", ft_recursive_factorial(1));
	printf("%d\n", ft_recursive_factorial(2));
	printf("%d\n", ft_recursive_factorial(3));
	printf("%d\n", ft_recursive_factorial(4));
	printf("%d\n", ft_recursive_factorial(6));
	printf("%d\n", ft_recursive_factorial(8));
	printf("%d\n", ft_recursive_factorial(10));
	printf("%d\n", ft_recursive_factorial(16));
	printf("%d\n", ft_recursive_factorial(24));
	printf("%d\n", ft_recursive_factorial(120));
	printf("%d\n", ft_recursive_factorial(720));
	return (0);
}