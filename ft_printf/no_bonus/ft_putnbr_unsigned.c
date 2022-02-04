#include "ft_printf.h"

// REMOVE THIS FUNCTIONS LATER

void	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
}
