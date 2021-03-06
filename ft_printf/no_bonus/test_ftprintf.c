#include <stdio.h>
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

static void	ft_check_params(const char **str, t_par *params)
{
	while (**str == '#' || **str == '+' || **str == '-' || **str == ' '
			|| **str == '0')
	{
		if (**str == '0' && !params->minus)
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

	if (**str == '.')
	{
		params->zero = 0;
		params->dot = 0;
		++(*str);
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

static void	ft_output(va_list arg, t_par *params, int *r)
{
	long	l;

	if (params->type == 'c')
		ft_output_char(params, va_arg(arg, unsigned int), r);
	else if(params->type == 's')
		ft_output_str(params, va_arg(arg, char *), r);
	else if (params->type == 'd' || params->type == 'i')
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
		{
			ft_putchar(*str, &r);
			++str;
		}
	}
	va_end(arg);
	return (r);
}

int	main(void)
{
	// printf("TESTING %%d with flags...........\n");
	// ft_printf("FT | TEST 01 | %d \n", 5);
	// printf("OR | TEST 01 | %d \n", 5);
	// ft_printf("FT | TEST 02 | %d\n", ft_printf("%d\n", 5));
	// printf("OR | TEST 02 | %d\n", printf("%d\n", 5));
	// ft_printf("FT | TEST 03 | %d\n", -115);
	// printf("OR | TEST 03 | %d\n", -115);
	// ft_printf("FT | TEST 04 | %2d\n", 5);
	// printf("OR | TEST 04 | %2d\n", 5);
	// ft_printf("FT | TEST 05 | %3d\n", 5);
	// printf("OR | TEST 05 | %3d\n", 5);
	// ft_printf("FT | TEST 06 | %d\n", ft_printf("%3d\n", 5));
	// printf("OR | TEST 06 | %d\n", printf("%3d\n", 5));
	// ft_printf("FT | TEST 07 | %4d \n", -5);
	// printf("OR | TEST 07 | %4d \n", -5);
	// ft_printf("FT | TEST 06 | %d\n", ft_printf("%4d\n", -5));
	// printf("OR | TEST 06 | %d\n", printf("%4d\n", -5));
	// ft_printf("FT | TEST 09 | %03d\n", 5);
	// printf("OR | TEST 09 | %03d\n", 5);
	// ft_printf("FT | TEST 10 | %04d\n", -5);
	// printf("OR | TEST 10 | %04d\n", -5);
	// ft_printf("FT | TEST 11 | %0-5d\n", 11);
	// printf("OR | TEST 11 | %0-5d\n", 11);
	// ft_printf("FT | TEST 12 | %0-5d\n", -11);
	// printf("OR | TEST 12 | %0-5d\n", -11);
	// ft_printf("FT | TEST 13 | %-05d\n", 33);
	// printf("OR | TEST 13 | %-05d\n", 33);
	// ft_printf("FT | TEST 14 | %0-05d\n", 44);
	// printf("OR | TEST 14 | %0-05d\n", 44);
	// ft_printf("FT | TEST 15 | %-0-5d\n", 55);
	// printf("OR | TEST 15 | %-0-5d\n", 55);
	// ft_printf("FT | TEST 16 | %-0-5.6d\n", -66);
	// printf("OR | TEST 16 | %-0-5.6d\n", -66);
	// ft_printf("FT | TEST 16.5 | %d\n", ft_printf("%-0-5.6d\n", -66));
	// printf("OR | TEST 16.5 | %d\n", printf("%-0-5.6d\n", -66));
	// ft_printf("FT | TEST 17 | %-0-5.6d\n", 66);
	// printf("OR | TEST 17 | %-0-5.6d\n", 66);
	// ft_printf("FT | TEST 18 | %.5d\n", 15);
	// printf("OR | TEST 18 | %.5d\n", 15);
	// ft_printf("FT | TEST 19 | % 4d\n", 7);
	// printf("OR | TEST 19 | % 4d\n", 7);
	// ft_printf("FT | TEST 21 | % .5d\n", 25);
	// printf("OR | TEST 21 | % .5d\n", 25);
	// ft_printf("FT | TEST 22 | %+d\n", 7);
	// printf("OR | TEST 22 | %+d\n", 7);
	// ft_printf("FT | TEST 23 | %+5d\n", 8);
	// printf("OR | TEST 23 | %+5d\n", 8);
	// ft_printf("FT | TEST 24 | %+4d\n", -8);
	// printf("OR | TEST 24 | %+4d\n", -8);
	// ft_printf("FT | TEST 25 | %-6d\n", 11);
	// printf("OR | TEST 25 | %-6d\n", 11);
	// ft_printf("FT | TEST 20 | %4 d\n", 3);
	// printf("OR | TEST 20 | %4 d\n", 3);
	// ft_printf("FT | TEST 26 | %d\n", ft_printf("%-6d %06d % 5d %+4d %.5d %#d\n", 11, 12, 13, 14, 15, 16));
	// printf("OR | TEST 26 | %d\n", printf("%-6d %06d % 5d %+4d %.5d %#d\n", 11, 12, 13, 14, 15, 16));
	// ft_printf("FT | TEST 27 | %d%d%d\n", 11, 12, 13);
	// printf("OR | TEST 27 | %d%d%d\n", 11, 12, 13);
	// ft_printf("FT | TEST 28 | %d %d %d\n", 11, 12, 13);
	// printf("OR | TEST 28 | %d %d %d\n", 11, 12, 13);

	// printf("TESTING %i with flags...........\n");
	// ft_printf("FT | TEST 01 | %i \n", 5);
	// printf("OR | TEST 01 | %i \n", 5);
	// ft_printf("FT | TEST 02 | %i\n", ft_printf("%i\n", 5));
	// printf("OR | TEST 02 | %i\n", printf("%i\n", 5));
	// ft_printf("FT | TEST 03 | %i\n", -115);
	// printf("OR | TEST 03 | %i\n", -115);
	// ft_printf("FT | TEST 04 | %2i\n", 5);
	// printf("OR | TEST 04 | %2i\n", 5);
	// ft_printf("FT | TEST 05 | %3i\n", 5);
	// printf("OR | TEST 05 | %3i\n", 5);
	// ft_printf("FT | TEST 06 | %i\n", ft_printf("%3i\n", 5));
	// printf("OR | TEST 06 | %i\n", printf("%3i\n", 5));
	// ft_printf("FT | TEST 07 | %4i \n", -5);
	// printf("OR | TEST 07 | %4i \n", -5);
	// ft_printf("FT | TEST 06 | %i\n", ft_printf("%4i\n", -5));
	// printf("OR | TEST 06 | %i\n", printf("%4i\n", -5));
	// ft_printf("FT | TEST 09 | %03i\n", 5);
	// printf("OR | TEST 09 | %03i\n", 5);
	// ft_printf("FT | TEST 10 | %04i\n", -5);
	// printf("OR | TEST 10 | %04i\n", -5);
	// ft_printf("FT | TEST 11 | %0-5i\n", 11);
	// printf("OR | TEST 11 | %0-5i\n", 11);
	// ft_printf("FT | TEST 12 | %0-5i\n", -11);
	// printf("OR | TEST 12 | %0-5i\n", -11);
	// ft_printf("FT | TEST 13 | %-05i\n", 33);
	// printf("OR | TEST 13 | %-05i\n", 33);
	// ft_printf("FT | TEST 14 | %0-05i\n", 44);
	// printf("OR | TEST 14 | %0-05i\n", 44);
	// ft_printf("FT | TEST 15 | %-0-5i\n", 55);
	// printf("OR | TEST 15 | %-0-5i\n", 55);
	// ft_printf("FT | TEST 16 | %-0-5.6i\n", -66);
	// printf("OR | TEST 16 | %-0-5.6i\n", -66);
	// ft_printf("FT | TEST 16.5 | %i\n", ft_printf("%-0-5.6i\n", -66));
	// printf("OR | TEST 16.5 | %i\n", printf("%-0-5.6i\n", -66));
	// ft_printf("FT | TEST 17 | %-0-5.6i\n", 66);
	// printf("OR | TEST 17 | %-0-5.6i\n", 66);
	// ft_printf("FT | TEST 18 | %.5i\n", 15);
	// printf("OR | TEST 18 | %.5i\n", 15);
	// ft_printf("FT | TEST 19 | % 4i\n", 7);
	// printf("OR | TEST 19 | % 4i\n", 7);
	// ft_printf("FT | TEST 21 | % .5i\n", 25);
	// printf("OR | TEST 21 | % .5i\n", 25);
	// ft_printf("FT | TEST 22 | %+i\n", 7);
	// printf("OR | TEST 22 | %+i\n", 7);
	// ft_printf("FT | TEST 23 | %+5i\n", 8);
	// printf("OR | TEST 23 | %+5i\n", 8);
	// ft_printf("FT | TEST 24 | %+4i\n", -8);
	// printf("OR | TEST 24 | %+4i\n", -8);
	// ft_printf("FT | TEST 25 | %-6i\n", 11);
	// printf("OR | TEST 25 | %-6i\n", 11);
	// ft_printf("FT | TEST 26 | %-6i %06i % 5i %+4i %.5i %#i\n", 11, 12, 13, 14, 15, 16);
	// printf("OR | TEST 26 | %-6i %06i % 5i %+4i %.5i %#i\n", 11, 12, 13, 14, 15, 16);
	// ft_printf("FT | TEST 26 | %i\n", ft_printf("%-6i %06i % 5i %+4i %.5i %#i\n", 11, 12, 13, 14, 15, 16));
	// printf("OR | TEST 26 | %i\n", printf("%-6i %06i % 5i %+4i %.5i %#i\n", 11, 12, 13, 14, 15, 16));
	// ft_printf("FT | TEST 27 | %i%i%i\n", 11, 12, 13);
	// printf("OR | TEST 27 | %i%i%i\n", 11, 12, 13);
	// ft_printf("FT | TEST 28 | %i %i %i\n", 11, 12, 13);
	// printf("OR | TEST 28 | %i %i %i\n", 11, 12, 13);

	// printf("TESTING %%c with flags...........\n");
	// ft_printf("FT | TEST 1 | %c\n", 'a');
	// printf("OR | TEST 1 | %c\n", 'a');
	// ft_printf("FT | TEST 2 | %c %c %c\n", 'a', 'b', 'c');
	// printf("OR | TEST 2 | %c %c %c\n", 'a', 'b', 'c');
	// ft_printf("FT | TEST 3 | %c%c%c\n", 'a', 'b', 'c');
	// printf("OR | TEST 3 | %c%c%c\n", 'a', 'b', 'c');
	// ft_printf("FT | TEST 4 | %d\n", ft_printf("%c %c %c\n", 'a', 'b', 'c'));
	// printf("OR | TEST 4 | %d\n", printf("%c %c %c\n", 'a', 'b', 'c'));
	// ft_printf("FT | TEST 5 | %-c\n", 'a');
	// printf("OR | TEST 5 | %-c\n", 'a');
	// ft_printf("FT | TEST 5.5 | %-6c\n", 'a');
	// printf("OR | TEST 5.5 | %-6c\n", 'a');
	// ft_printf("FT | TEST 6 | %-5c\n", 'b');
	// printf("OR | TEST 6 | %-5c\n", 'b');
	// ft_printf("FT | TEST 7 | %5c\n", 'c');
	// printf("OR | TEST 7 | %5c\n", 'c');
	// ft_printf("FT | TEST 8 | %0c\n", 'd');
	// printf("OR | TEST 8 | %0c\n", 'd');
	// ft_printf("FT | TEST 9 | %04c\n", 'e');
	// printf("OR | TEST 9 | %04c\n", 'e');
	// ft_printf("FT | TEST 10 | %#c\n", 'f');
	// printf("OR | TEST 10 | %#c\n", 'f');
	// ft_printf("FT | TEST 11 | %+c\n", 'g');
	// printf("OR | TEST 11 | %+c\n", 'g');
	// ft_printf("FT | TEST 12 | % c\n", 'h');
	// printf("OR | TEST 12 | % c\n", 'h');
	// ft_printf("FT | TEST 13 | %.c\n", 'i');
	// printf("OR | TEST 13 | %.c\n", 'i');
	// ft_printf("FT | TEST 14 | %.5c\n", 'i');
	// printf("OR | TEST 14 | %.5c\n", 'i');
	// ft_printf("FT | TEST 15 | %0-5c\n", 'j');
	// printf("OR | TEST 15 | %0-5c\n", 'j');
	// ft_printf("FT | TEST 16 | %d\n", ft_printf("%0-5c\n", 'j'));
	// printf("OR | TEST 16 | %d\n", printf("%0-5c\n", 'j'));
	// ft_printf("FT | TEST 17 | %-0-6c\n", 'k');
	// printf("OR | TEST 17 | %-0-6c\n", 'k');
	// ft_printf("FT | TEST 18 | %005c\n", 'l');
	// printf("OR | TEST 18 | %005c\n", 'l');
	
	printf("TESTING %%s with flags...........\n");
	ft_printf("FT | TEST 1 | %s\n", "test");
	printf("OR | TEST 1 | %s\n", "test");
	// ft_printf("FT | TEST 2 | %\n", );
	// printf("OR | TEST 2 | %\n", );
	// ft_printf("FT | TEST 3 | %\n", );
	// printf("OR | TEST 3 | %\n", );
	// ft_printf("FT | TEST 4 | %\n", );
	// printf("OR | TEST 4 | %\n", );
	// ft_printf("FT | TEST 5 | %\n", );
	// printf("OR | TEST 5 | %\n", );
	// ft_printf("FT | TEST 6 | %\n", );
	// printf("OR | TEST 6 | %\n", );
	// ft_printf("FT | TEST 7 | %\n", );
	// printf("OR | TEST 7 | %\n", );
	// ft_printf("FT | TEST 8 | %\n", );
	// printf("OR | TEST 8 | %\n", );
	// ft_printf("FT | TEST 9 | %\n", );
	// printf("OR | TEST 9 | %\n", );
	// ft_printf("FT | TEST 10 | %\n", );
	// printf("OR | TEST 10 | %\n", );
	// ft_printf("FT | TEST 11 | %\n", );
	// printf("OR | TEST 11 | %\n", );
	// ft_printf("FT | TEST 12 | %\n", );
	// printf("OR | TEST 12 | %\n", );
	// ft_printf("FT | TEST 13 | %\n", );
	// printf("OR | TEST 13 | %\n", );
	// ft_printf("FT | TEST 14 | %\n", );
	// printf("OR | TEST 14 | %\n", );
	// ft_printf("FT | TEST 15 | %\n", );
	// printf("OR | TEST 15 | %\n", );
	// ft_printf("FT | TEST 16 | %\n", );
	// printf("OR | TEST 16 | %\n", );
	// ft_printf("FT | TEST 17 | %\n", );
	// printf("OR | TEST 17 | %\n", );
	// ft_printf("FT | TEST 18 | %\n", );
	// printf("OR | TEST 18 | %\n", );
	// ft_printf("FT | TEST 19 | %\n", );
	// printf("OR | TEST 19 | %\n", );
	// ft_printf("FT | TEST 20 | %\n", );
	// printf("OR | TEST 20 | %\n", );
	// ft_printf("FT | TEST 21 | %\n", );
	// printf("OR | TEST 21 | %\n", );
	// ft_printf("FT | TEST 22 | %\n", );
	// printf("OR | TEST 22 | %\n", );
	// ft_printf("FT | TEST 23 | %\n", );
	// printf("OR | TEST 23 | %\n", );
	// ft_printf("FT | TEST 24 | %\n", );
	// printf("OR | TEST 24 | %\n", );
	// ft_printf("FT | TEST 25 | %\n", );
	// printf("OR | TEST 25 | %\n", );

	// printf("TESTING % with flags...........\n");
	// ft_printf("FT | TEST 1 | %\n", );
	// printf("OR | TEST 1 | %\n", );
	// ft_printf("FT | TEST 2 | %\n", );
	// printf("OR | TEST 2 | %\n", );
	// ft_printf("FT | TEST 3 | %\n", );
	// printf("OR | TEST 3 | %\n", );
	// ft_printf("FT | TEST 4 | %\n", );
	// printf("OR | TEST 4 | %\n", );
	// ft_printf("FT | TEST 5 | %\n", );
	// printf("OR | TEST 5 | %\n", );
	// ft_printf("FT | TEST 6 | %\n", );
	// printf("OR | TEST 6 | %\n", );
	// ft_printf("FT | TEST 7 | %\n", );
	// printf("OR | TEST 7 | %\n", );
	// ft_printf("FT | TEST 8 | %\n", );
	// printf("OR | TEST 8 | %\n", );
	// ft_printf("FT | TEST 9 | %\n", );
	// printf("OR | TEST 9 | %\n", );
	// ft_printf("FT | TEST 10 | %\n", );
	// printf("OR | TEST 10 | %\n", );
	// ft_printf("FT | TEST 11 | %\n", );
	// printf("OR | TEST 11 | %\n", );
	// ft_printf("FT | TEST 12 | %\n", );
	// printf("OR | TEST 12 | %\n", );
	// ft_printf("FT | TEST 13 | %\n", );
	// printf("OR | TEST 13 | %\n", );
	// ft_printf("FT | TEST 14 | %\n", );
	// printf("OR | TEST 14 | %\n", );
	// ft_printf("FT | TEST 15 | %\n", );
	// printf("OR | TEST 15 | %\n", );
	// ft_printf("FT | TEST 16 | %\n", );
	// printf("OR | TEST 16 | %\n", );
	// ft_printf("FT | TEST 17 | %\n", );
	// printf("OR | TEST 17 | %\n", );
	// ft_printf("FT | TEST 18 | %\n", );
	// printf("OR | TEST 18 | %\n", );
	// ft_printf("FT | TEST 19 | %\n", );
	// printf("OR | TEST 19 | %\n", );
	// ft_printf("FT | TEST 20 | %\n", );
	// printf("OR | TEST 20 | %\n", );
	// ft_printf("FT | TEST 21 | %\n", );
	// printf("OR | TEST 21 | %\n", );
	// ft_printf("FT | TEST 22 | %\n", );
	// printf("OR | TEST 22 | %\n", );
	// ft_printf("FT | TEST 23 | %\n", );
	// printf("OR | TEST 23 | %\n", );
	// ft_printf("FT | TEST 24 | %\n", );
	// printf("OR | TEST 24 | %\n", );
	// ft_printf("FT | TEST 25 | %\n", );
	// printf("OR | TEST 25 | %\n", );

	// printf("TESTING % with flags...........\n");
	// ft_printf("FT | TEST 1 | %\n", );
	// printf("OR | TEST 1 | %\n", );
	// ft_printf("FT | TEST 2 | %\n", );
	// printf("OR | TEST 2 | %\n", );
	// ft_printf("FT | TEST 3 | %\n", );
	// printf("OR | TEST 3 | %\n", );
	// ft_printf("FT | TEST 4 | %\n", );
	// printf("OR | TEST 4 | %\n", );
	// ft_printf("FT | TEST 5 | %\n", );
	// printf("OR | TEST 5 | %\n", );
	// ft_printf("FT | TEST 6 | %\n", );
	// printf("OR | TEST 6 | %\n", );
	// ft_printf("FT | TEST 7 | %\n", );
	// printf("OR | TEST 7 | %\n", );
	// ft_printf("FT | TEST 8 | %\n", );
	// printf("OR | TEST 8 | %\n", );
	// ft_printf("FT | TEST 9 | %\n", );
	// printf("OR | TEST 9 | %\n", );
	// ft_printf("FT | TEST 10 | %\n", );
	// printf("OR | TEST 10 | %\n", );
	// ft_printf("FT | TEST 11 | %\n", );
	// printf("OR | TEST 11 | %\n", );
	// ft_printf("FT | TEST 12 | %\n", );
	// printf("OR | TEST 12 | %\n", );
	// ft_printf("FT | TEST 13 | %\n", );
	// printf("OR | TEST 13 | %\n", );
	// ft_printf("FT | TEST 14 | %\n", );
	// printf("OR | TEST 14 | %\n", );
	// ft_printf("FT | TEST 15 | %\n", );
	// printf("OR | TEST 15 | %\n", );
	// ft_printf("FT | TEST 16 | %\n", );
	// printf("OR | TEST 16 | %\n", );
	// ft_printf("FT | TEST 17 | %\n", );
	// printf("OR | TEST 17 | %\n", );
	// ft_printf("FT | TEST 18 | %\n", );
	// printf("OR | TEST 18 | %\n", );
	// ft_printf("FT | TEST 19 | %\n", );
	// printf("OR | TEST 19 | %\n", );
	// ft_printf("FT | TEST 20 | %\n", );
	// printf("OR | TEST 20 | %\n", );
	// ft_printf("FT | TEST 21 | %\n", );
	// printf("OR | TEST 21 | %\n", );
	// ft_printf("FT | TEST 22 | %\n", );
	// printf("OR | TEST 22 | %\n", );
	// ft_printf("FT | TEST 23 | %\n", );
	// printf("OR | TEST 23 | %\n", );
	// ft_printf("FT | TEST 24 | %\n", );
	// printf("OR | TEST 24 | %\n", );
	// ft_printf("FT | TEST 25 | %\n", );
	// printf("OR | TEST 25 | %\n", );

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
	return (0);
}