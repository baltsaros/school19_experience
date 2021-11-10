#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "ft_tail.h"

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		n;

	i = 0;
	sign = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		++i;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + str[i] - '0';
		++i;
	}
	return (sign * n);
}

int	write_file(char *bytes, char *path)
{
	int		i;
	int		fd;
	int		r_bytes;
	char	buf[SIZE];

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(2, strerror(errno));
		return (0);
	}
	r_bytes = read(fd, buf, SIZE);
	if (r_bytes < 0)
	{
		ft_putstr_fd(2, strerror(errno));
		return (0);
	}
	else
	{
		i = r_bytes - ft_atoi(bytes);
		while (i < r_bytes)
		{
			write(1, &buf[i], 1);
			++i;
		}
	}
	close(fd);
	return (1);
}

int	write_file_def(char *path)
{
	int		i;
	int		lines;
	int		fd;
	int		r_bytes;
	char	buf[SIZE];

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(2, strerror(errno));
		return (0);
	}
	r_bytes = read(fd, buf, SIZE);
	lines = 1;
	i = r_bytes;
	if (r_bytes < 0)
	{
		ft_putstr_fd(2, strerror(errno));
		return (0);
	}
	else
	{
		while (i && lines <= 10)
		{
			if (buf[i] == '\n')
				++lines;
			--i;
		}
	}
	while (i + 2 < r_bytes)
	{
		write(1, &buf[i + 2], 1);
		++i;
	}
	close(fd);
	return (1);
}

int		ft_tail(int n, char **files)
{
	int		i;

	if (files[1][0] == '-' && files[1][1] == 'c')
	{
		i = 3;
		while (i < n + 1)
		{
			write_file(files[2], files[i]);
			++i;
		}
	}
	else
	{
		i = 1;
		while (i < n + 1)
		{
			write_file_def(files[i]);
			++i;
		}
	}
	return (1);
}
