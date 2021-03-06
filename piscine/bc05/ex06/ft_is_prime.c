int	ft_sieve(int n, int i)
{
	if (n % i == 0)
		return(0);
	if (i * i > n)
		return(1);
	else
		return(ft_sieve(n, i + 1));
}

int	ft_is_prime(int nb)
{
	if (nb > 2)
		return(ft_sieve(nb, 2));
	if (nb == 2)
		return (1);
	else
		return (0);
}

#include <stdio.h>
int	main()
{
	int		nb;

	nb = 100;
	while (nb > -3)
	{
		printf("%d --- %d\n", nb, ft_is_prime(nb));
		--nb;
	}
	return (0);
}
