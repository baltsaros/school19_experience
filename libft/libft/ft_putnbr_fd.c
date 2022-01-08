#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		ft_putchar_fd('-', fd);
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		nbr = nbr % 10;
	}
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', fd);
}

// int		main(void)
// {
// 	int		n;
// 	int		fd;

// 	fd = 1;
// 	n = 0;
// 	ft_putnbr_fd(n, fd);
// 	write(1, "\n", 1);
// 	n = -5;
// 	ft_putnbr_fd(n, fd);
// 	write(1, "\n", 1);
// 	n = -123;
// 	ft_putnbr_fd(n, fd);
// 	write(1, "\n", 1);
// 	n = -2147483648;
// 	ft_putnbr_fd(n, fd);
// 	write(1, "\n", 1);
// 	n = 3;
// 	ft_putnbr_fd(n, fd);
// 	write(1, "\n", 1);
// 	n = 2147483647;
// 	ft_putnbr_fd(n, fd);
// 	write(1, "\n", 1);
// 	return (0);
// }