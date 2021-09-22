#include <unistd.h>

void	ft_putchar(char n)
{
	write(1, &n, 1);
}

void	ft_print_alphabet(void)
{
	char	n;
	n = '0';
	while (n <= '9')
	{
		ft_putchar(n);
		n++;
	}
}

int	main()
{
	ft_print_alphabet();
	return 0;
}
