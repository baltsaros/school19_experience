int	ft_recursive_factorial(int nb)
{
	if (nb > 1)
	{
		nb = nb * ft_recursive_factorial(nb - 1);
		return (nb);
	}
	if (nb == 0 || nb == 1)
		return (1);
	else
		return(0);
}

#include <stdio.h>
int	main()
{
	printf("%d\n", ft_recursive_factorial(-2));
	printf("%d\n", ft_recursive_factorial(0));
	printf("%d\n", ft_recursive_factorial(1));
	printf("%d\n", ft_recursive_factorial(2));
	printf("%d\n", ft_recursive_factorial(3));
	printf("%d\n", ft_recursive_factorial(4));
	printf("%d\n", ft_recursive_factorial(5));
	printf("%d\n", ft_recursive_factorial(6));
	return (0);
}