#include "ft_printf.h"

void	ft_putchar(char c, int *r)
{
	write(1, &c, 1);
	++(*r);
}
