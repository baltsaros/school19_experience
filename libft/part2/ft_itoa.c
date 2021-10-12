#include <stdlib.h>
#include <stdio.h>

static size_t	ft_intlen(int n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
		++i;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
static char	*ft_addnbr(int n, char *s, int i)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = -n;
		s[0] = '-';
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_addnbr(nbr / 10, s, i - 1);
		nbr = nbr % 10;
	}
	if (nbr < 10)
	{
		s[i - 1] = nbr + '0';
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s_int;
	unsigned int	i;

	i = ft_intlen(n);
	s_int = (char *)malloc(sizeof(*s_int) * (i + 1));
	if (NULL == s_int)
		return (NULL);
	ft_addnbr(n, s_int, i);
	s_int[i] = '\0';
	return (s_int);
}

int	main(void)
{
	int	n;

	n = 0;
	printf("n is %d, itoa is %s\n", n, ft_itoa(n));
	n = 1;
	printf("n is %d, itoa is %s\n", n, ft_itoa(n));
	n = 12;
	printf("n is %d, itoa is %s\n", n, ft_itoa(n));
	n = 123;
	printf("n is %d, itoa is %s\n", n, ft_itoa(n));
	n = 2147483647;
	printf("n is %d, itoa is %s\n", n, ft_itoa(n));
	n = -1;
	printf("n is %d, itoa is %s\n", n, ft_itoa(n));
	n = -12;
	printf("n is %d, itoa is %s\n", n, ft_itoa(n));
	n = -123;
	printf("n is %d, itoa is %s\n", n, ft_itoa(n));
	n = -2147483648;
	printf("n is %d, itoa is %s\n", n, ft_itoa(n));
	return (0);
}
