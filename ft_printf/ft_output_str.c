#include "ft_printf.h"

static int	ft_decrease(int *width)
{
	if (*width > 0)
	{
		--(*width);
		return (1);
	}
	return (0);
}

void	ft_output_str(t_par *params, char *str, int *r)
{
	if (!str)
	{
		ft_output_str(params, "(null)", r);
		return ;
	}
	if (params->dot != 0)
		params->width -= ft_strlen(str);
	while ((params->width > 0) && params->zero && ft_decrease(&params->width))
		ft_putchar('0', r);
	while ((params->width > 0) && !params->minus && ft_decrease(&params->width))
		ft_putchar(' ', r);
	while (*str != '\0')
	{
		if (params->dot >= 0 && !(ft_decrease(&params->dot)))
			break ;
		ft_putchar(*str, r);
		++str;
	}
	while ((params->width > 0) && params->minus && ft_decrease(&params->width))
		ft_putchar(' ', r);
}
