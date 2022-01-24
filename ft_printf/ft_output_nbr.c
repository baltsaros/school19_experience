#include "ft_printf.h"
static void	ft_width(int *width)
{
	if (*width)
	{
		--width;
		return (1);
	}
	return (0);
}

static void	ft_check_params(t_par *params, int nbr, int *r)
{
	if (params->plus && nbr >= 0)
		ft_putchar('+', r);
	else if (params->space && nbr >= 0)
		ft_putchar(' ', r);
	else
		ft_putchar(' ', r);
}

void	ft_output_nbr(t_par *params, int nbr, int *r)
{
	unsigned int	nb;

	ft_check_params(params, nbr, r);
	if (nbr < 0)
	{
		ft_putchar('-', r);
		nb = -nbr;
	}
	else
		nb = nbr;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, r);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + '0', r);
}
