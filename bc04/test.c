#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_base_control(char *base)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (base[j] == '\0'|| base[j + 1] == '\0' || base[j] == '-'
		|| base[j] == '+' || base[j] < 32 || base[j] > 126)
		return (0);
	while (base[j])
	{
		if (base[j] == base[i])
			return (0);
		++j;
		i = j + 1;
	}
	return (1);
}

void	ft_putnbr(int nbr, int i, char *base)
{
	unsigned int	nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb > 0)
	{
		ft_putnbr(nb / i, i, base);
		nb = nb % i;
		if (nb < 10)
			ft_putchar(nb + base[i]);
		if (nb >= 10)
			ft_putchar(nb + base[i]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	while (base[i])
		++i;
	if (ft_base_control(base))
		ft_putnbr(nbr, i, base);
}

int	main()
{
	int		nbr;
	char	*base;

	nbr = 1239;
	ft_putnbr_base(nbr, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "01");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "0123456789ABCDEF");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "poneyvif");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "abcd");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "pon");
	ft_putchar('\n');
	return (0);
	//base = "0123456789"
	//base = "01"
	//base = "0123456789ABCDEF"
	//base = "poneyvif"
}
