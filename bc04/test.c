#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;
	
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = -nb;
	}
	else
		nbr = nb;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
}

int	main()
{
	int		nb;

	nb = -2147483648;
	ft_putnbr(nb);
	ft_putchar('\n');
	nb = 0;
	ft_putnbr(nb);
	ft_putchar('\n');
	nb = 2147483647;
	ft_putnbr(nb);
	ft_putchar('\n');
	nb = -400;
	ft_putnbr(nb);
	ft_putchar('\n');
	nb = 42;
	ft_putnbr(nb);
	ft_putchar('\n');
	nb = 7;
	ft_putnbr(nb);
	ft_putchar('\n');
	nb = -5;
	ft_putnbr(nb);
	ft_putchar('\n');
	return (0);
}
