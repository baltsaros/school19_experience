#include "ft_printf.h"

void	ft_putstr(char *str, int *r)
{
	int		i;

	if (!str)
	{
		ft_putstr("(null)", r);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		++i;
		++(*r);
	}
}
