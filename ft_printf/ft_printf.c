#include "ft_printf.h"

static int	*ft_check_flag(va_list c, char ch, int *r)
{
	long	l;

	if (ch == 'p')
	{
		l = va_arg(c, long);
		ft_putstr("0x", r);
		if (l < 0)
			ft_putptr_add_un(l, "0123456789abcdef", r);
		else
			ft_putptr_add(l, "0123456789abcdef", r);
	}
	if (ch == 'd')
		ft_putnbr_base(va_arg(c, int), "0123456789", r);
	if (ch == 'i')
		ft_putnbr_base(va_arg(c, int), "0123456789", r);
	if (ch == 'u')
		ft_putnbr_base_un(va_arg(c, unsigned int), "0123456789", r);
	if (ch == 'x')
		ft_putnbr_base_un(va_arg(c, int), "0123456789abcdef", r);
	if (ch == 'X')
		ft_putnbr_base_un(va_arg(c, int), "0123456789ABCDEF", r);
	return (r);
}

int	ft_printf(const char *str, ...)
{
	va_list	c;
	int		i;
	int		r;

	va_start(c, str);
	i = 0;
	r = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			++i;
			if (str[i] == 'c')
				ft_putchar(va_arg(c, unsigned int), &r);
			else if (str[i] == 's')
				ft_putstr(va_arg(c, char *), &r);
			else if (str[i] == '%')
				ft_putchar('%', &r);
			else
				ft_check_flag(c, str[i], &r);
		}
		else
			ft_putchar(str[i], &r);
		++i;
	}
	va_end(c);
	return (r);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int		d = 9;
// 	char	c = 'a';
// 	char	s[6] = "Hello";

// 	ft_printf("TESTING FT\n");
// 	printf("TESTING OR\n");
// 	ft_printf("FT | TEST 1 | %c\n", c);
// 	printf("OR | TEST 1 | %c\n", c);
// 	ft_printf("FT | TEST 2 | %c %c\n", c, '1');
// 	printf("OR | TEST 2 | %c %c\n", c, '1');
// 	ft_printf("FT | TEST 3 | %d\n", d);
// 	printf("OR | TEST 3 | %d\n", d);
// 	ft_printf("FT | TEST 4 | %d\n", -99);
// 	printf("OR | TEST 4 | %d\n", -99);
// 	ft_printf("FT | TEST 5 | %s\n", s);
// 	printf("OR | TEST 5 | %s\n", s);
// 	ft_printf("FT | TEST 5.5 | %s\n", "");
// 	printf("OR | TEST 5.5 | %s\n", "");
// 	ft_printf("FT | TEST 6 | %i\n", -9);
// 	printf("OR | TEST 6 | %i\n", -9);
// 	ft_printf("FT | TEST 6.5 | %i\n", 10);
// 	printf("OR | TEST 6.5 | %i\n", 10);
// 	ft_printf("FT | TEST 7 | %u\n", -23);
// 	printf("OR | TEST 7 | %u\n", -23);
// 	ft_printf("FT | TEST 8 | %u\n", 101);
// 	printf("OR | TEST 8 | %u\n", 101);
// 	ft_printf("FT | TEST 9 | %x\n", 578);
// 	printf("OR | TEST 9 | %x\n", 578);
// 	ft_printf("FT | TEST 10 | %x\n", -307);
// 	printf("OR | TEST 10 | %x\n", -307);
// 	ft_printf("FT | TEST 11 | %X\n", 1234);
// 	printf("OR | TEST 11 | %X\n", 1234);
// 	ft_printf("FT | TEST 12 | %X\n", -1234);
// 	printf("OR | TEST 12 | %X\n", -1234);
// 	ft_printf("FT | TEST 13 | %%\n");
// 	printf("OR | TEST 13 | %%\n");
// 	ft_printf("FT | TEST 14 | %%%%\n");
// 	printf("OR | TEST 14 | %%%%\n");
// 	ft_printf("FT | TEST 15 | %p\n", -1);
// 	printf("OR | TEST 15 | %p\n", -1);
// 	ft_printf("FT | TEST 16 | %p\n", 177);
// 	printf("OR | TEST 16 | %p\n", 177);
// 	ft_printf("FT | TEST 17 | %c%s%c\n", 'A', "oooo", 'A');
// 	printf("OR | TEST 17 | %c%s%c\n", 'A', "oooo", 'A');
// 	ft_printf("FT | TEST 18 | %d%%%d%p\n", 99, 11, -40);
// 	printf("OR | TEST 18 | %d%%%d%p\n", 99, 11, -40);
// 	ft_printf("FT | TEST 19 | %d\n", ft_printf("xyz"));
// 	printf("OR | TEST 19 | %d\n", printf("xyz"));
// 	ft_printf("FT | TEST 20 | %d\n", ft_printf("%u", -1234));
// 	printf("OR | TEST 20 | %d\n", printf("%u", -1234));
// 	ft_printf("FT | TEST 21 | %c \n", '0');
// 	printf("OR | TEST 21 | %c \n", '0');
// 	ft_printf("FT | TEST 22 | %d\n", ft_printf("%c \n", '0'));
// 	printf("OR | TEST 22 | %d\n", printf("%c \n", '0'));
// 	ft_printf("FT | TEST 23 | %c %c %c \n", '0', 0, '1');
// 	printf("OR | TEST 23 | %c %c %c \n", '0', 0, '1');
// 	ft_printf("FT | TEST 24 | %d\n", ft_printf("%c %c %c \n", '0', 0, '1'));
// 	printf("OR | TEST 24 | %d\n", printf("%c %c %c \n", '0', 0, '1'));
// 	ft_printf("FT | TEST 25 | NULL %s NULL\n", NULL);
// 	printf("OR | TEST 25 | NULL %s NULL\n", NULL);
// 	ft_printf("FT | TEST 26 | %d\n", ft_printf("NULL %s NULL\n", NULL));
// 	printf("OR | TEST 26 | %d\n", printf("NULL %s NULL\n", NULL));
// 	ft_printf("FT | TEST 27 | %d\n", -100);
// 	printf("OR | TEST 27 | %d\n", -100);
// 	ft_printf("FT | TEST 28 | %d\n", ft_printf("%d\n", -100));
// 	printf("OR | TEST 28 | %d\n", printf("%d\n", -100));
// 	ft_printf("FT | TEST 29 | %p\n", 17);
// 	printf("OR | TEST 29 | %p\n", 17);
// 	ft_printf("FT | TEST 30 | %d\n", ft_printf("\n%p", 17));
// 	printf("OR | TEST 30 | %d\n", printf("\n%p", 17));
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	// ft_printf("FT | TEST  | \n", );
// 	// printf("OR | TEST  | \n", );
// 	return (0);
// }