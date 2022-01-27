#include "ft_printf.h"

static int	ft_nbrlen(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr)
	{
		nbr = nbr / 16;
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

static void	ft_putnbr_un(unsigned int nb, int *r)
{
	if (nb >= 16)
	{
		ft_putnbr_un(nb / 16, r);
		nb = nb % 16;
	}
	if (nb < 10)
		ft_putchar(nb + '0', r);
	else
		ft_putchar(nb + 55, r);
}

void	ft_output_hexX(t_par *params, unsigned int nbr, int *r)
{
	int	check;
	int	check2;

	check = 0;
	if (params->dot == 0 && nbr == 0)
		check = 1;
	check2 = 0;
	if (params->width > params->dot)
		check2 = 1;
	params->dot = params->dot - ft_nbrlen(nbr);
	if (!params->minus && params->dot >= 0 && params->width > 0 && params->width > params->dot)
		params->width -= params->dot;
	else if (params->dot >= 0 && params->width > 0 && params->width < params->dot)
		params->width = params->dot - params->width + check;
	params->width = params->width - ft_nbrlen(nbr) + check;
	if (params->sharp && nbr)
		params->width -= 2;
	if (check2)
	{
		while (!params->zero && !params->minus && ft_decrease(&params->width))
			ft_putchar(' ', r);
	}
	if (params->sharp && nbr)
		ft_putstr("0X", r);
	while (params->zero && ft_decrease(&params->width))
		ft_putchar('0', r);
	while (params->dot >= 0 && ft_decrease(&params->dot))
	{
		ft_putchar('0', r);
		--params->width;
	}	
	if (!check)
		ft_putnbr_un(nbr, r);
	while (params->minus && ft_decrease(&params->width))
		ft_putchar(' ', r);
}
