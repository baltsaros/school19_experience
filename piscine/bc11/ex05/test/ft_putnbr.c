#include <unistd.h>
#include "doop.h"

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
