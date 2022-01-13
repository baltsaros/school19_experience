#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		++i;
	}
	write(fd, "\n", 1);
}

int		main(void)
{
	char	s[] = "Hello world!";
	int		fd;

	fd = 1;
	ft_putendl_fd(s, fd);
	return (0);
}
