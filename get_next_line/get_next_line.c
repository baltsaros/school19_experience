#include "get_next_line.h"

static size_t	ft_find_line(char *input)
{
	size_t	i;

	i = 0;
	while (input[i] && input[i] != '\n')
		++i;
	return (i);
}

char	*read_line(char *rest, int fd)
{
	ssize_t	r_bytes;
	char	*buf;

	buf = malloc(sizeof *buf * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	r_bytes = 1;
	while (!ft_strchr(buf, '\n') && r_bytes > 0)
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes < 0)
		{
			free(buf);
			return (0);
		}
		buf[r_bytes] = '\0';
		rest = ft_strjoin(rest, buf);
	}
	free(buf);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char		*rest;
	char			*ret;
	char			*tmp;
	ssize_t			len;
	ssize_t			i;
	ssize_t			j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!rest)
	{
		// printf("rest1 |%s|\n", rest);
		rest = malloc(sizeof *rest * 1);
		if (!rest)
			return (0);
		rest[0] = '\0';
	}
	rest = read_line(rest, fd);
	// printf("rest2 |%s|\n", rest);
	len = ft_find_line(rest) + 2;
	ret = malloc(sizeof *ret * (len));
	if (!ret)
		return (0);
	// printf("ret1 |%s|\n", ret);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		ret[i] = rest[i];
		++i;
	}
	if (rest[i])
	{
		ret[i] = '\n';
		++i;
	}
	ret[i] = '\0';
	j = 0;
	if (!rest[i])
		return (ret);
	while (rest[i + j])
		++j;
	tmp = malloc(sizeof *tmp * (j + 1));
	if (!tmp)
		return (0);
	j = 0;
	while (rest[i + j])
	{
		tmp[j] = rest[i + j];
		++j;
	}
	tmp[j] = '\0';
	free(rest);
	rest = malloc(sizeof *rest * (j + 1));
		if (!rest)
			return (0);
	j = 0;
	while (tmp[j])
	{
		rest[j] = tmp[j];
		++j;
	}
	rest[j] = '\0';
	free(tmp);
	// printf("ret2 |%s|\n", ret);
	return (ret);
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*ret;
	char	*ret1;
	char	*ret2;
	int		fd;
	size_t	i;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("OPEN ERROR\n");
		return (0);
	}
	i = 0;
	while (i < 5)
	{
		ret = get_next_line(fd);
		printf("str is %s", ret);
		free(ret);
		++i;
	}
	// ret = get_next_line(fd);
	// printf("str is %s", ret);
	// ret1 = get_next_line(fd);
	// printf("str is %s", ret1);
	// ret2 = get_next_line(fd);
	// printf("str is %s", ret2);
	return (0);
}