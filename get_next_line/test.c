#include "get_next_line.h"

static size_t	ft_find_line(char *input)
{
	size_t	i;

	i = 0;
	while (input[i] && input[i] != '\n')
		++i;
	return (i);
}

char	*get_next_line(int fd)
{
	static char		*rest;
	char			*ret;
	char			*buf;
	ssize_t			len;
	ssize_t			i;
	ssize_t			r_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!rest)
	{
		printf("rest1 |%s|\n", rest);
		rest = malloc(sizeof *rest * (BUFFER_SIZE + 1));
		if (!rest)
			return (0);
	}
	buf = malloc(sizeof *buf * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	r_bytes = 1;
	// printf("buf1 %s\n", buf);
	// printf("r_bytes %d\nstrchr is %d\n", r_bytes, ft_strchr(buf, '\n'));
	while (!(ft_strchr(buf, '\n')) && r_bytes > 0)
	{
		// printf("loop\n");
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes < 0)
			return (0);
		buf[r_bytes] = '\0';
		rest = ft_strjoin(rest, buf);
		if (!rest)
		{
			free(rest);
			return (0);
		}
	}
	free(buf);
	// printf("rest |%s|\n", rest);
	len = ft_find_line(rest) + 2;
	ret = malloc(sizeof *ret * (len));
	if (!ret)
		return (0);
	ft_strlcpy(ret, rest, len);
	// printf("len %d\nret |%s|\n", len, ret);
	// printf("rest |%s|\n", rest);
	i = 0;
	// printf("rest[len - 1 + i] is %c\nrest[len + i] is %c\n", rest[len - 1 + i], rest[len + i]);
	while (rest[len - 1 + i])
		++i;
	buf = malloc(sizeof *buf * (i + 1));
	if (!buf)
		return (0);
	ft_strlcpy(buf, rest + len - 1, i + 1);
	ft_bzero(rest, len + 1 + i);
	ft_strlcpy(rest, buf, i + 1);
	// printf("rest |%s|\n", rest);
	// printf("buf |%s|\n", buf);
	free(buf);
	// printf("rest |%s|\n", rest);
	return (ret);
}


#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*ret;
	int		fd;
	size_t	i;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("OPEN ERROR\n");
		return (0);
	}
	i = 0;
	while (i < 3)
	{
		ret = get_next_line(fd);
		printf("str is %s", ret);
		free(ret);
		++i;
	}
	return (0);
}