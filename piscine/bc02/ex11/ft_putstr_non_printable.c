#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_convert_into_hex(char ch)
{
	if (ch == 0)
		write(1, "0", 1);
	if (ch > 0)
	{
		ft_convert_into_hex(ch / 16);
		ch = ch % 16;
		if (ch < 10)
			ft_putchar(ch + 48);
		if (ch >= 10)
			ft_putchar(ch + 87);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &str[i], 1);
			++i;
		}
		else
		{
			write(1, "\\", 1);
			ft_convert_into_hex(str[i]);
			++i;
		}
	}


}

int		main(void)
{
	char	str[] = "Coucou\ntu vas bien \v?";

	ft_putstr_non_printable(str);
	write(1, "\n", 1);
	return (0);
}
