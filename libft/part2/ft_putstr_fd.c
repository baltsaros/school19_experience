#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		++i;
	}
}

int		main(void)
{
	char	s[] = "Hello world!";
	int		fd;

	fd = 1;
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\n", fd);
	return (0);
}
