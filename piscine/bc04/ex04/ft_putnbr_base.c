#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_base_control(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || (base[i] < 33
			&& base[i] > 126))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

void	ft_putnbr(int nbr, unsigned int i, char *base)
{
	unsigned int	nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb >= i)
	{
		ft_putnbr(nb / i, i, base);
		nb = nb % i;
	}
	if (nb < i)
		ft_putchar(base[nb]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		++i;
	if (ft_base_control(base))
		ft_putnbr(nbr, i, base);
}

int	main()
{
	int		nbr;
	// char	*base;

	nbr = 1234678;
	ft_putnbr_base(nbr, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "9876543210");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "9876543");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "01");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "0123456789ABCDEF");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "poneyvif");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "abcdef");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "helop");
	ft_putchar('\n');
	return (0);
	//base = "0123456789"
	//base = "01"
	//base = "0123456789ABCDEF"
	//base = "poneyvif"
}
