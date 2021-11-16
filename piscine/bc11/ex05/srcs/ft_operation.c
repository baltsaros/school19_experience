#include <unistd.h>
#include "doop.h"

void	ft_operation(int a, int b, char *o)
{
	if (*o == '+')
		ft_putnbr(a + b);
	else if (*o == '-')
		ft_putnbr(a - b);
	else if (*o == '*')
		ft_putnbr(a * b);
	else if (*o == '/')
	{
		if (b == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_putnbr(a / b);
	}
	else if (*o == '%')
	{
		if (b == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(a % b);
	}
	ft_putchar('\n');
}
