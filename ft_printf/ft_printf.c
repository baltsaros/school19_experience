#include "ft_printf.h"

static int	ft_check_flag(va_list c, char ch, int i)
{
	int	j;

	if (ch == 'p')
	{
		j = va_arg(c, int);
		ft_putstr("0x");
		if (j < 0)
			ft_putnbr_base_un(j, "0123456789abcdef", i);	
		else
			ft_putnbr_base(j, "0123456789abcdef");
	}
	if (ch == 'd')
		ft_putnbr_base(va_arg(c, int), "0123456789");
	if (ch == 'i')
		ft_putnbr_base(va_arg(c, int), "0123456789");
	if (ch == 'u')
		ft_putnbr_base_un(va_arg(c, unsigned int), "0123456789", i);
	if (ch == 'x')
		ft_putnbr_base_un(va_arg(c, int), "0123456789abcdef", i);
	if (ch == 'X')
		ft_putnbr_base_un(va_arg(c, int), "0123456789ABCDEF", i);
	return (i);
}

int	ft_printf(const char* str, ...)
{
	va_list	c;
	int	i;
	int	r;

	va_start(c, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			++i;
			ft_check_flag(c, str[i], i);
			if (str[i] == 'c')
				ft_putchar(va_arg(c, unsigned int));
			if (str[i] == 's')
				ft_putstr(va_arg(c, char *));
			if (str[i] == '%')
				ft_putchar('%');
		}
		else
			ft_putchar(str[i]);
			++i;
	}
	va_end(c);
	return (i);
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
	ft_printf("FT | TEST 5.5 | %s\n", "");
	printf("OR | TEST 5.5 | %s\n", "");
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
	ft_printf("FT | TEST 17 | %c%s%c\n", 'A', "oooo", 'A');
	printf("OR | TEST 17 | %c%s%c\n", 'A', "oooo", 'A');
	ft_printf("FT | TEST 18 | %d%%%d%p\n", 99, 11, -40);
	printf("OR | TEST 18 | %d%%%d%p\n", 99, 11, -40);
	ft_printf("FT | TEST 19 | %d\n", ft_printf("xyz"));
	printf("OR | TEST 19 | %d\n", printf("xyz"));
	ft_printf("FT | TEST 20 | %d\n", ft_printf("%u", -1234));
	printf("OR | TEST 20 | %d\n", printf("%u", -1234));
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