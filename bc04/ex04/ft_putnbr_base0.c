#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_base_deci(int nbr)
{
	unsigned int	nb;
	
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb >= 10)
	{
		ft_base_deci(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
}

int	ft_base_binary(int nbr, char *base)
{
	int		i;
	int		base_bi[32];

	i = 0;
	while (nbr > 0)
	{
		base_bi[i] = nbr % 2;
		ft_putchar(base_bi[i]);
		nbr = nbr / 2;
		++i;
	}
	return (base_bi);
}

char	ft_base_hexadec(int nbr, char *base)
{
	char	base_hex[32];
	int		tmp;
	int		i;
	int		j;

	j = 0;
	while (nbr > 0)
	{
		tmp = nbr % 16;
		if (tmp < 10)
			base_hex[j] = tmp + 48;
		else
			base_hex[j] = tmp + 55;
		nbr = nbr / 16;
		++j;
	}
	i = 0;
	while (i < j)
	{
		tmp = base_hex[i];
		base_hex[i] = base_hex[j - 1];
		ft_putchar(base_hex[i]);
		base_hex[j - 1] = tmp;
		++i;
		--j;
	}
	return (base_hex);
}

void	ft_putnbr_base(int nbr, char *base)
{

}


int	main()
{
	int		nbr;
	char	*base;

	nbr = 2549;
	base = "01";
	ft_base_deci(nbr);
	ft_putchar('\n');
	ft_base_binary(nbr, base);
	ft_putchar('\n');
	ft_base_hexadec(nbr, base);
	ft_putchar('\n');
	return (0);
}