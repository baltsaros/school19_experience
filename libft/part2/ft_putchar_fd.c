#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		main(void)
{
	int		fd;

	fd = 2;
	ft_putchar_fd('a', fd);
	ft_putchar_fd('\n', fd);
	return (0);
}
