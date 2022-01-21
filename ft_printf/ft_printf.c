#include "ft_printf.h"

int	ft_printf(const char* str, ...)
{
	va_list	c;
	size_t	i;
	int	j;
	char	*s;

	va_start(c, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			++i;
			if (str[i] == 'c')
			{
				j = va_arg(c, int);
				ft_putchar(j);
			}
			if (str[i] == 's')
			{
				s = va_arg(c, char *);
				ft_putstr(s);
			}
			if (str[i] == 'p')
			{
				j = va_arg(c, int);
				ft_putstr("0x");
				if (j < 0)
					ft_putnbr_base_un(j, "0123456789abcdef");	
				else
					ft_putnbr_base(j, "0123456789abcdef");
			}
			if (str[i] == 'd')
			{
				j = va_arg(c, int);
				ft_putnbr_base(j, "0123456789");
			}
			if (str[i] == 'i')
			{
				j = va_arg(c, int);
				ft_putnbr_base(j, "0123456789");
			}
			if (str[i] == 'u')
			{
				j = va_arg(c, unsigned int);
				ft_putnbr_base_un(j, "0123456789");
			}
			if (str[i] == 'x')
			{
				j = va_arg(c, int);
				ft_putnbr_base_un(j, "0123456789abcdef");
			}
			if (str[i] == 'X')
			{
				j = va_arg(c, int);
				ft_putnbr_base_un(j, "0123456789ABCDEF");
			}
			if (str[i] == '%')
			{
				ft_putchar('%');
			}
		}
		else
			ft_putchar(str[i]);
			++i;
	}
	va_end(c);
	return (0);
}

#include <stdio.h>
int	main(void)
{
	int		d = 9;
	char	c = 'a';
	char	s[6] = "Hello";

	ft_printf("TESTING FT\n");
	printf("TESTING OR\n");
	ft_printf("FT | TEST 1 | %c\n", c);
	printf("OR | TEST 1 | %c\n", c);
	ft_printf("FT | TEST 2 | %c %c\n", c, '1');
	printf("OR | TEST 2 | %c %c\n", c, '1');
	ft_printf("FT | TEST 3 | %d\n", d);
	printf("OR | TEST 3 | %d\n", d);
	ft_printf("FT | TEST 4 | %d\n", -99);
	printf("OR | TEST 4 | %d\n", -99);
	ft_printf("FT | TEST 5 | %s\n", s);
	printf("OR | TEST 5 | %s\n", s);
	ft_printf("FT | TEST 6 | %i\n", -9);
	printf("OR | TEST 6 | %i\n", -9);
	ft_printf("FT | TEST 6.5 | %i\n", 10);
	printf("OR | TEST 6.5 | %i\n", 10);
	ft_printf("FT | TEST 7 | %u\n", -23);
	printf("OR | TEST 7 | %u\n", -23);
	ft_printf("FT | TEST 8 | %u\n", 101);
	printf("OR | TEST 8 | %u\n", 101);
	ft_printf("FT | TEST 9 | %x\n", 578);
	printf("OR | TEST 9 | %x\n", 578);
	ft_printf("FT | TEST 10 | %x\n", -307);
	printf("OR | TEST 10 | %x\n", -307);
	ft_printf("FT | TEST 11 | %X\n", 1234);
	printf("OR | TEST 11 | %X\n", 1234);
	ft_printf("FT | TEST 12 | %X\n", -1234);
	printf("OR | TEST 12 | %X\n", -1234);
	ft_printf("FT | TEST 13 | %%\n");
	printf("OR | TEST 13 | %%\n");
	ft_printf("FT | TEST 14 | %%%%\n");
	printf("OR | TEST 14 | %%%%\n");
	ft_printf("FT | TEST 15 | %p\n", -1);
	printf("OR | TEST 15 | %p\n", -1);
	ft_printf("FT | TEST 16 | %p\n", 177);
	printf("OR | TEST 16 | %p\n", 177);
	// ft_printf("FT | TEST 17 | \n", );
	// printf("OR | TEST 17 | \n", );
	// ft_printf("FT | TEST 18 | \n", );
	// printf("OR | TEST 18 | \n", );
	// ft_printf("FT | TEST 19 | \n", );
	// printf("OR | TEST 19 | \n", );
	// ft_printf("FT | TEST 20 | \n", );
	// printf("OR | TEST 20 | \n", );
	// ft_printf("FT | TEST 21 | \n", );
	// printf("OR | TEST 21 | \n", );
	// ft_printf("FT | TEST 22 | \n", );
	// printf("OR | TEST 22 | \n", );
	// ft_printf("FT | TEST 23 | \n", );
	// printf("OR | TEST 23 | \n", );
	// ft_printf("FT | TEST 24 | \n", );
	// printf("OR | TEST 24 | \n", );
	// ft_printf("FT | TEST 25 | \n", );
	// printf("OR | TEST 25 | \n", );
	// ft_printf("FT | TEST  | \n", );
	// printf("OR | TEST  | \n", );
	// ft_printf("FT | TEST  | \n", );
	// printf("OR | TEST  | \n", );
	// ft_printf("FT | TEST  | \n", );
	// printf("OR | TEST  | \n", );
	// ft_printf("FT | TEST  | \n", );
	// printf("OR | TEST  | \n", );
	// ft_printf("FT | TEST  | \n", );
	// printf("OR | TEST  | \n", );
	// ft_printf("FT | TEST  | \n", );
	// printf("OR | TEST  | \n", );
	// ft_printf("FT | TEST  | \n", );
	// printf("OR | TEST  | \n", );
	// ft_printf("FT | TEST  | \n", );
	// printf("OR | TEST  | \n", );
	return (0);
}