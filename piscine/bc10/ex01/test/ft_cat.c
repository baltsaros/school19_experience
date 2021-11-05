#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "ft_cat.h"

int		write_file(char *path)
{
	int		i;
	int		fd;
	int		r_bytes;
	char	buf[SIZE];

	fd = open(path, O_RDONLY);
	if (fd < 0)			// ERR1
	{
		ft_putstr_fd(1, strerror(errno));
		return (0);
	}
	i = 0;
	r_bytes = read(fd, buf, SIZE);
	if (r_bytes < 0)	// ERR2
	{
		ft_putstr_fd(2, strerror(errno));
		return (0);
	}
	else
	{
		while (i < r_bytes)
		{
			write(1, &buf[i], 1);
			++i;
		}
	}
	close(fd);
	return (1);
}

int		write_line(void)
{
	int		r_bytes;
	char	*buf[SIZE];

	while ((r_bytes = read(0, buf, SIZE)) > 0)
		write(1, buf, r_bytes);
	if (r_bytes < 0)	// ERR2
	{
		ft_putstr_fd(2, strerror(errno));
		return (0);
	}
	return (1);
}

int		ft_cat(int n, char **files)
{
	int		i;

	i = 1;
	if (n == 1)
		write_line();
	else
	{
		while (i < n + 1)
		{
			write_file(files[i]);
			++i;
		}
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	ft_cat(argc, argv);
	return (0);
}
