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

void	ft_base_binary(int nbr)
{
	if (nbr > 0)
	{
		ft_base_binary(nbr / 2);
		ft_putchar(nbr % 2 + '0');
	}
}

void	ft_base_hexadec(int nbr)
{
	if (nbr > 0)
	{
		ft_base_hexadec(nbr / 16);
		nbr = nbr % 16;
	}
	if (nbr < 10 && nbr > 0)
		ft_putchar(nbr + 48);
	if (nbr >= 10 && nbr < 17)
		ft_putchar(nbr + 55);
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
	ft_base_binary(nbr);
	ft_putchar('\n');
	ft_base_hexadec(nbr);
	ft_putchar('\n');
	return (0);
}
