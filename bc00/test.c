#include <unistd.h>

void	ft_putchar(char n)	
{
	write(1, &n, 1);
}

void ft_print_alphabet(void)
{
	char	n;
	char	a;
	n = 0;
	a = n / 10;
	ft_putchar(a);
	a = n / 10 + '0';
	ft_putchar(a);
}

int	main(void)
{
	ft_print_alphabet();
	return 0;
}
