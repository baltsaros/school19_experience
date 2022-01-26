#include "ft_printf.h"

static int	ft_nbrlen(int nbr, int include)
{
	int	len;

	len = 0;
	if (nbr < 0 && include)
		++len;
	if (nbr == 0)
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
	int	check;

	check = 0;
	if (params->dot == 0 && nbr == 0)
		check = 1;
	params->width = params->width - ft_nbrlen(nbr, 1) + check;
	params->dot -= ft_nbrlen(nbr, 0);
	if (params->dot > 0)
		params->width = params->width - params->dot;
	if (params->plus && nbr >= 0)
		--params->width;
	if (params->space && (!params->plus) && params->width <= 0 && nbr >= 0)
		ft_putchar(' ', r);
	while (!params->zero && !params->minus && ft_decrease(&params->width))
		ft_putchar(' ', r);
	if (params->plus && nbr >= 0)
		ft_putchar('+', r);
	if (nbr < 0)
		ft_putchar('-', r);
	while ((params->zero && ft_decrease(&params->width)) || ft_decrease(&params->dot))
		ft_putchar('0', r);
	if (!check)
		ft_putnbr(nbr, r);
	while (params->minus && (params->dot <= 0) && ft_decrease(&params->width))
		ft_putchar(' ', r);
}

