#include <stdio.h>

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

int	ft_find_next_prime(int nb)
{
	while(ft_is_prime(nb) != 1)
		++nb;
	return(nb);
}

int	main(void)
{
	int		nb;

	nb = 50;
	// printf("nb is %d, next prime is %d\n", nb, ft_find_next_prime(nb));
	while (nb > -2)
	{
		printf("nb is %d, next prime is %d\n", nb, ft_find_next_prime(nb));
		--nb;
	}
	return(0);
}