#include "ft_printf.h"

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr)
	{
		nbr = nbr / 10;
		++len;
	}
	return (len);
}

static int	ft_decrease(int *width)
{
	if (*width > 0)
	{
		--(*width);
		return (1);
	}
	return (0);
}

static int	ft_precision(int *precision)
{
	if (*precision > 0)
	{
		--precision;
		return (1);
	}
	return (0);
}

static void	ft_putnbr(int nbr, int *r)
{
	unsigned int	nb;

	if (nbr < 0)
		nb = -nbr;
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

void	ft_output_nbr(t_par *params, int nbr, int *r)
{
	params->width = params->width - ft_nbrlen(nbr);
	if (params->plus && nbr >= 0)
		--params->width;
	while (params->space && ft_decrease(&params->width))
		ft_putchar(' ', r);
	while (params->plus && ft_decrease(&params->width))
		ft_putchar(' ', r);
	if (params->plus && nbr >= 0)
		ft_putchar('+', r);
	if (nbr < 0)
		ft_putchar('-', r);
	while (params->zero && ft_decrease(&params->width))
		ft_putchar('0', r);
	params->dot = params->dot - ft_nbrlen(nbr);
	if (nbr < 0 && params->dot)
		++params->dot;
	while (ft_decrease(&params->dot))
		ft_putchar('0', r);
	ft_putnbr(nbr, r);
	while (params->minus && ft_decrease(&params->width))
		ft_putchar(' ', r);
}

