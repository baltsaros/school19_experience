#include "ftprintf_m.h"

static void	ft_putstr_count(char *str, int *ret)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		ret += 6;
	}
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			++(*ret);
			++i;
		}
	}
}

void	ft_putchar_count(char c, int *ret)
{
	write(1, &c, 1);
	++(*ret);
}

static int	nbr_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr)
	{
		nbr = nbr / 10;
		++len;
	}
	return (len);
}

static int	nbr_len_hex(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr)
	{
		nbr = nbr / 16;
		++len;
	}
	return (len);
}

static int	str_len(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str)
	{
		++len;
		++str;
	}
	return (len);
}

static int	decrease(int *param)
{
	if (*param > 0)
	{
		--(*param);
		return (1);
	}
	return (0);
}

static void	ft_putnbr(int nbr, int *ret)
{
	unsigned int	nb;

	if (nbr < 0)
		nb = - nbr;
	else
		nb = nbr;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, ret);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar_count(nb + '0', ret);
}

static void	ft_putnbr_hex(unsigned int nbr, int *ret)
{
	if (nbr >= 16)
	{
		ft_putnbr_hex(nbr / 16, ret);
		nbr = nbr % 16;
	}
	if (nbr < 10)
		ft_putchar_count(nbr + '0', ret);
	else
		ft_putchar_count(nbr + 87, ret);
}

void	ft_output_nbr(int nbr, t_par *params, int *ret)
{
	int	len;

	len = nbr_len(nbr);
	if (nbr == 0 && params->dot == 0)
		len = 0;
	if (nbr < 0 && params->dot > 0)
		++params->dot;
	params->width = params->width - len;
	params->dot = params->dot - len;
	while (params->width > params->dot && decrease(&params->width))
		ft_putchar_count(' ', ret);
	if (nbr < 0)
		ft_putchar_count('-', ret);
	while (params->dot && decrease(&params->dot))
		ft_putchar_count('0', ret);
	if (len)
		ft_putnbr(nbr, ret);
}

void	ft_output_str(char *str, t_par *params, int *ret)
{
	int	len;
	int	check;

	check = 0;
	if (params->dot == 0)
		check = 1;
	len = str_len(str);
	if (!str)
		len = 6;
	if (params->dot != 0)
		params->width = params->width - len;
	while (params->width && decrease(&params->width))
		ft_putchar_count(' ', ret);
	if (!check)
		ft_putstr_count(str, ret);
}

void	ft_output_hex(unsigned int nbr, t_par *params, int *ret)
{
	int	len;

	len = nbr_len_hex(nbr);
	if (nbr == 0 && params->dot == 0)
		len = 0;
	params->width = params->width - len;
	params->dot = params->dot - len;
	while (params->width > params->dot && decrease(&params->width))
		ft_putchar_count(' ', ret);
	while (params->dot && decrease(&params->dot))
		ft_putchar_count('0', ret);
	if (len)
		ft_putnbr_hex(nbr, ret);
}