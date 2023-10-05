#include "ftprintf_m.h"

static void	set_params(t_par *params)
{
	params->width = 0;
	params->dot = -1;
	params->type = 0;
}

static void	check_params(t_par *params, const char **str)
{
	while (**str >= '0' && **str <= '9')
	{
		params->width = params->width * 10 + **str - '0';
		++(*str);
	}
	if (**str == '.')
	{
		params->dot = 0;
		++(*str);
		while (**str >= '0' && **str <= '9')
		{
			params->dot = params->dot * 10 + **str - '0';
			++(*str);
		}
	}
	if (**str == 'd' || **str == 'x' || **str == 's')
	{
		params->type = **str;
		++(*str);
	}
}

static void	ft_output(va_list arg, t_par *params, int *ret)
{
	if (params->type == 'd')
		ft_output_nbr(va_arg(arg, int), params, ret);
	else if (params->type == 's')
		ft_output_str(va_arg(arg, char *), params, ret);
	else if (params->type == 'x')
		ft_output_hex(va_arg(arg, unsigned int), params, ret);
}

int		ft_printf(const char *str, ...)
{
	va_list	arg;
	t_par	params;
	int		ret;

	ret = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			set_params(&params);
			check_params(&params, &str);
			ft_output(arg, &params, &ret);
		}
		else
		{
			ft_putchar_count(*str, &ret);
			++str;
		}
	}
	va_end(arg);
	return (ret);
}

#include <stdio.h>
int		main(void)
{
	// ft_printf("test 01\n");
	// printf("test 01\n");
	// ft_printf("\nret is %d\n", ft_printf("test 02"));
	// printf("\nret is %d\n", printf("test 02"));

	// printf("TESTING %%d\n");
	// ft_printf("FT: TEST 00 | %d\n", 42);
	// printf("OR: TEST 00 | %d\n", 42);
	// ft_printf("FT: TEST 01 | %d\n", ft_printf("\n%d\n", 42));
	// printf("OR: TEST 01 | %d\n", printf("\n%d\n", 42));
	// ft_printf("FT: TEST 02 | %d\n", -42);
	// printf("OR: TEST 02 | %d\n", -42);
	// ft_printf("FT: TEST 03 | %d\n", ft_printf("\n%d\n", -42));
	// printf("OR: TEST 03 | %d\n", printf("\n%d\n", -42));
	// ft_printf("FT: TEST 04 | %5d\n", 13);
	// printf("OR: TEST 04 | %5d\n", 13);
	// ft_printf("FT: TEST 05 | %5d\n", -13);
	// printf("OR: TEST 05 | %5d\n", -13);
	// ft_printf("FT: TEST 06 | %d\n", ft_printf("\n%5d\n", -12));
	// printf("OR: TEST 06 | %d\n", ft_printf("\n%5d\n", -12));
	// ft_printf("FT: TEST 07 | %5.d\n", 7);
	// printf("OR: TEST 07 | %5.d\n", 7);
	// ft_printf("FT: TEST 08 | %5.5d\n", 8);
	// printf("OR: TEST 08 | %5.5d\n", 8);
	// ft_printf("FT: TEST 09 | %5.7d\n", -9);
	// printf("OR: TEST 09 | %5.7d\n", -9);
	// ft_printf("TEST 10 | %5.d\n", -10);
	// printf("TEST 10 | %5.d\n", -10);
	// ft_printf("TEST 11 | %d%d%d%d\n", 11, 22, 33, -44);
	// printf("TEST 11 | %d%d%d%d\n", 11, 22, 33, -44);
	// ft_printf("TEST 12 | %d\n", ft_printf("\n%d%d%d%d\n", 11, 22, 33, -44));
	// printf("TEST 12 | %d\n", printf("\n%d%d%d%d\n", 11, 22, 33, -44));
	// ft_printf("TEST 13 | %d %5d %.6d %3.6d\n", -11, 12, -13, -14);
	// printf("TEST 13 | %d %5d %.6d %3.6d\n", -11, 12, -13, -14);
	// ft_printf("TEST 14 | %d\n", ft_printf("\n%d %5d %.6d %3.d\n", -11, 12, -13, -14));
	// printf("TEST 14 | %d\n", printf("\n%d %5d %.6d %3.d\n", -11, 12, -13, -14));
	// ft_printf("TEST 15 | %d\n", 0);
	// printf("TEST 15 | %d\n", 0);
	// ft_printf("TEST 16 | %5d\n", 0);
	// printf("TEST 16 | %5d\n", 0);
	// ft_printf("TEST 17 | %.d\n", 0);
	// printf("TEST 17 | %.d\n", 0);
	// ft_printf("TEST 17 | %.5d\n", 0);
	// printf("TEST 17 | %.5d\n", 0);

	// printf("TESTING %%s\n");
	// ft_printf("FT: TEST 00 | %s\n", "a");
	// printf("OR: TEST 00 | %s\n", "a");
	// ft_printf("FT: TEST 01 | %s%s%s\n", "a", "b", "c");
	// printf("OR: TEST 01 | %s%s%s\n", "a", "b", "c");
	// ft_printf("FT: TEST 02 | %s %s %s\n", "11", "22", "33");
	// printf("OR: TEST 02 | %s %s %s\n", "11", "22", "33");
	// ft_printf("FT: TEST 03 | %d\n", ft_printf("\n%s %s %s\n", "11", "22", "33"));
	// printf("OR: TEST 03 | %d\n", printf("\n%s %s %s\n", "11", "22", "33"));
	// ft_printf("FT: TEST 04 | %5s\n", "e");
	// printf("OR: TEST 04 | %5s\n", "e");
	// ft_printf("FT: TEST 05 | %5.s\n", "f");
	// printf("OR: TEST 05 | %5.s\n", "f");
	// ft_printf("FT: TEST 06 | %5.1s\n", "j");
	// printf("OR: TEST 06 | %5.1s\n", "j");
	// ft_printf("FT: TEST 07 | %5.5s\n", "h");
	// printf("OR: TEST 07 | %5.5s\n", "h");
	// ft_printf("FT: TEST 08 | %5.7s\n", "g");
	// printf("OR: TEST 08 | %5.7s\n", "g");
	// ft_printf("FT: TEST 09 | %.s\n", "ha");
	// printf("OR: TEST 09 | %.s\n", "ha");
	// ft_printf("FT: TEST 10 | %.6s\n", "eh");
	// printf("OR: TEST 10 | %.6s\n", "eh");
	// ft_printf("FT: TEST 11 | %s\n", NULL);
	// printf("OR: TEST 11 | %s\n", NULL);
	// ft_printf("FT: TEST 12 | %.s\n", NULL);
	// printf("OR: TEST 12 | %.s\n", NULL);
	// ft_printf("FT: TEST 13 | %8s\n", NULL);
	// printf("OR: TEST 13 | %8s\n", NULL);

	printf("TESTING %%s\n");
	ft_printf("FT: TEST 00 | %x\n", 42);
	printf("OR: TEST 00 | %x\n", 42);
	ft_printf("FT: TEST 01 | %d\n", ft_printf("\n%x\n", 42));
	printf("OR: TEST 01 | %d\n", printf("\n%x\n", 42));
	ft_printf("FT: TEST 02 | %x\n", -42);
	printf("OR: TEST 02 | %x\n", -42);
	ft_printf("FT: TEST 03 | %d\n", ft_printf("\n%x\n", -42));
	printf("OR: TEST 03 | %d\n", printf("\n%x\n", -42));
	ft_printf("FT: TEST 04 | %x\n", 0);
	printf("OR: TEST 04 | %x\n", 0);
	ft_printf("FT: TEST 05 | %.x\n", 0);
	printf("OR: TEST 05 | %.x\n", 0);
	ft_printf("FT: TEST 06 | %4x\n", 0);
	printf("OR: TEST 06 | %4x\n", 0);
	ft_printf("FT: TEST 07 | %.5x\n", 0);
	printf("OR: TEST 07 | %.5x\n", 0);
	ft_printf("FT: TEST 08 | %10x\n", 120);
	printf("OR: TEST 08 | %10x\n", 120);
	ft_printf("FT: TEST 09 | %.15x\n", -120);
	printf("OR: TEST 09 | %.15x\n", -120);
	// ft_printf("FT: TEST 10 | %x\n", );
	// printf("OR: TEST 10 | %x\n", );
	return (0);
}