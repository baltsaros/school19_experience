#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_base_deci(int nbr)
{
	unsigned int	nb;
	
	if (nbr < 0)
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

void	ft_base_oct(int nbr)
{
	if (nbr > 0)
	{
		ft_base_oct(nbr / 8);
		ft_putchar(nbr % 8 + '0');
	}
}
void	ft_putnbr_base(int nbr, char *base)
{
	if (base == "0123456789")
		ft_base_deci(nbr);
	if (base == "01")
		ft_base_binary(nbr);
	if (base == "0123456789ABCDEF")
		ft_base_hexadec(nbr);
	if (base == "poneyvif")
		ft_base_oct(nbr);
}

int	main()
{
	int		nbr;
	//char	*base;

	nbr = 400;
	ft_putnbr_base(nbr, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "01");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "0123456789ABCDEF");
	ft_putchar('\n');
	ft_putnbr_base(nbr, "poneyvif");
	ft_putchar('\n');
	return (0);
	//base = "0123456789"
	//base = "01"
	//base = "0123456789ABCDEF"
	//base = "poneyvif"
}
