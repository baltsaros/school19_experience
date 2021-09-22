#include <unistd.h>

void	ft_putchar(char z)
{
	write(1, &z, 1);
}

void ft_print_alphabet(void)
{
	char	z;
	z = 'z';
	while (z >= 'a')
	{
		ft_putchar(z);
		z--;
	}
}

int	main(void)
{
	ft_print_alphabet();
	return 0;
}
