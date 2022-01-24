#include "ft_printf.h"

static void	ft_set_params(t_par *params)
{
	params->zero = 0;
	params->minus = 0;
	params->dot = -1;
	params->space = 0;
	params->plus = 0;
	params->sharp = 0;
	params->width = 0;
	params->type = 0;
}

static void	ft_check_params(char **str, t_par *params)
{
	while (**str == '#' || **str == '+' || **str == '-' || **str == ' '
			|| **str == '0')
	{
		if (**str == '0')
			params->zero = 1;
		else if (**str == ' ')
			params->space = 1;
		else if (**str == '+')
		{
			params->space = 0;	
			params->plus = 1;
		}
		else if (**str == '-')
		{
			params->minus = 1;
			params->zero = 0;
		}
		else if (**str == '#')
			params->sharp = 1;
		++(*str);
	}

	while (ft_isdigit(**str))
	{
		params->width = params->width * 10 + **str - '0';
		++(*str);
	}	
// CHECK PARAMS AGAIN - NEED FOR CASES LIKE ("%04.7d\n", 500)
	if (**str == '.')
	{
		params->zero = 0;
		while (ft_isdigit(**str))
		{
			params->dot = params->dot * 10 + **str - '0';
			++(*str);
		}	
	}

	if (**str == 'd' || **str == 'i' || **str == 's' || **str == 'c'
			|| **str == 'x' || **str == 'X' || **str == 'u'
			|| **str == 'p' || **str == '%')
	{
		params->type = **str;
		++(*str);
	}
}

static void	*ft_output(va_list arg, t_par *params, int *r)
{
	long	l;

	if (params->type == 'c')
		ft_output_char(params, va_arg(arg, unsigned int), r);
	else if (params->type == 'd')
		ft_output_nbr(params, va_arg(arg, int), r);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_par	params;
	int		r;

	va_start(arg, str);
	r = 0;
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			ft_set_params(&params);
			ft_check_params(&str, &params);
			ft_output(arg, &params, &r);
		}
		else
			ft_putchar(*str, &r);
		++str;
	}
	va_end(arg);
	return (r);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int		d = 9;
// 	char	c = 'a';
// 	char	s[6] = "Hello";

// // 	ft_printf("TESTING FT\n");
// // 	printf("TESTING OR\n");
// // 	ft_printf("FT | TEST 1 | %c\n", c);
// // 	printf("OR | TEST 1 | %c\n", c);
// // 	ft_printf("FT | TEST 2 | %c %c\n", c, '1');
// // 	printf("OR | TEST 2 | %c %c\n", c, '1');
// // 	ft_printf("FT | TEST 3 | %d\n", d);
// // 	printf("OR | TEST 3 | %d\n", d);
// // 	ft_printf("FT | TEST 4 | %d\n", -99);
// // 	printf("OR | TEST 4 | %d\n", -99);
// // 	ft_printf("FT | TEST 5 | %s\n", s);
// // 	printf("OR | TEST 5 | %s\n", s);
// // 	ft_printf("FT | TEST 5.5 | %s\n", "");
// // 	printf("OR | TEST 5.5 | %s\n", "");
// // 	ft_printf("FT | TEST 6 | %i\n", -9);
// // 	printf("OR | TEST 6 | %i\n", -9);
// // 	ft_printf("FT | TEST 6.5 | %i\n", 10);
// // 	printf("OR | TEST 6.5 | %i\n", 10);
// // 	ft_printf("FT | TEST 7 | %u\n", -23);
// // 	printf("OR | TEST 7 | %u\n", -23);
// // 	ft_printf("FT | TEST 8 | %u\n", 101);
// // 	printf("OR | TEST 8 | %u\n", 101);
// // 	ft_printf("FT | TEST 9 | %x\n", 578);
// // 	printf("OR | TEST 9 | %x\n", 578);
// // 	ft_printf("FT | TEST 10 | %x\n", -307);
// // 	printf("OR | TEST 10 | %x\n", -307);
// // 	ft_printf("FT | TEST 11 | %X\n", 1234);
// // 	printf("OR | TEST 11 | %X\n", 1234);
// // 	ft_printf("FT | TEST 12 | %X\n", -1234);
// // 	printf("OR | TEST 12 | %X\n", -1234);
// // 	ft_printf("FT | TEST 13 | %%\n");
// // 	printf("OR | TEST 13 | %%\n");
// // 	ft_printf("FT | TEST 14 | %%%%\n");
// // 	printf("OR | TEST 14 | %%%%\n");
// // 	ft_printf("FT | TEST 15 | %p\n", -1);
// // 	printf("OR | TEST 15 | %p\n", -1);
// // 	ft_printf("FT | TEST 16 | %p\n", 177);
// // 	printf("OR | TEST 16 | %p\n", 177);
// // 	ft_printf("FT | TEST 17 | %c%s%c\n", 'A', "oooo", 'A');
// // 	printf("OR | TEST 17 | %c%s%c\n", 'A', "oooo", 'A');
// // 	ft_printf("FT | TEST 18 | %d%%%d%p\n", 99, 11, -40);
// // 	printf("OR | TEST 18 | %d%%%d%p\n", 99, 11, -40);
// // 	ft_printf("FT | TEST 19 | %d\n", ft_printf("xyz"));
// // 	printf("OR | TEST 19 | %d\n", printf("xyz"));
// // 	ft_printf("FT | TEST 20 | %d\n", ft_printf("%u", -1234));
// // 	printf("OR | TEST 20 | %d\n", printf("%u", -1234));
// // 	ft_printf("FT | TEST 21 | %c \n", '0');
// // 	printf("OR | TEST 21 | %c \n", '0');
// // 	ft_printf("FT | TEST 22 | %d\n", ft_printf("%c \n", '0'));
// // 	printf("OR | TEST 22 | %d\n", printf("%c \n", '0'));
// // 	ft_printf("FT | TEST 23 | %c %c %c \n", '0', 0, '1');
// // 	printf("OR | TEST 23 | %c %c %c \n", '0', 0, '1');
// // 	ft_printf("FT | TEST 24 | %d\n", ft_printf("%c %c %c \n", '0', 0, '1'));
// // 	printf("OR | TEST 24 | %d\n", printf("%c %c %c \n", '0', 0, '1'));
// // 	ft_printf("FT | TEST 25 | NULL %s NULL\n", NULL);
// // 	printf("OR | TEST 25 | NULL %s NULL\n", NULL);
// // 	ft_printf("FT | TEST 26 | %d\n", ft_printf("NULL %s NULL\n", NULL));
// // 	printf("OR | TEST 26 | %d\n", printf("NULL %s NULL\n", NULL));
// // 	ft_printf("FT | TEST 27 | %d\n", -100);
// // 	printf("OR | TEST 27 | %d\n", -100);
// // 	ft_printf("FT | TEST 28 | %d\n", ft_printf("%d\n", -100));
// // 	printf("OR | TEST 28 | %d\n", printf("%d\n", -100));
// // 	ft_printf("FT | TEST 29 | %p\n", 17);
// // 	printf("OR | TEST 29 | %p\n", 17);
// // 	ft_printf("FT | TEST 30 | %d\n", ft_printf("\n%p", 17));
// // 	printf("OR | TEST 30 | %d\n", printf("\n%p", 17));
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// // 	// ft_printf("FT | TEST  | \n", );
// // 	// printf("OR | TEST  | \n", );
// 	return (0);
// }