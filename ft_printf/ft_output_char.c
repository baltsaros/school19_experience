#include "ft_printf.h"

void	ft_output_char(t_par *params, char c, int *r)
{
	if (params->width > 0)
		(*r) += params->width;
	else
		++(*r);
	while (!params->minus && !params->zero && (params->width - 1 > 0))
	{
		write(1, " ", 1);
		--params->width;
	}
	while (params->zero && (params->width - 1 > 0))
	{
		write(1, "0", 1);
		--params->width;
	}
	write(1, &c, 1);
}
