int	ft_fibonacci(int index)
{
	int	n;

	if (index > 1)
	{
		--index;
		n = ft_fibonacci(index) + ft_fibonacci(index - 1);
		return (n);
	}
	if (index == 1)
		return (1);
	if (index == 0)
		return (0);
	else
		return (-1);

}

#include <stdio.h>
int	main()
{
	printf("%d\n", ft_fibonacci(-2));
	printf("%d\n", ft_fibonacci(0));
	printf("%d\n", ft_fibonacci(1));
	printf("%d\n", ft_fibonacci(2));
	printf("%d\n", ft_fibonacci(3));
	printf("%d\n", ft_fibonacci(4));
	printf("%d\n", ft_fibonacci(5));
	printf("%d\n", ft_fibonacci(10));
}