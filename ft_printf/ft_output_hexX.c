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
	params->width = params->width - ft_nbrlen(nbr);
	if (params->sharp && nbr)
		params->width -= 2;
	while ((params->dot <= 0) && !params->zero && !params->minus && ft_decrease(&params->width))
		ft_putchar(' ', r);
	if (params->sharp && nbr)
		ft_putstr("0X", r);
	while (params->zero && ft_decrease(&params->width))
		ft_putchar('0', r);
	params->dot = params->dot - ft_nbrlen(nbr);
	while (params->dot >= 0 && ft_decrease(&params->dot))
		ft_putchar('0', r);
	ft_putnbr_un(nbr, r);
	while (params->minus && (params->dot < 0) && ft_decrease(&params->width))
		ft_putchar(' ', r);
}
