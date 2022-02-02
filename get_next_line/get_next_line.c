#include "get_next_line.h"

static size_t	ft_find_line(char *input)
{
	size_t	i;

	i = 0;
	while (input[i] && input[i] != '\n')
		++i;
	return (i);
}

char	*read_line(char *tmp, int fd)
{
	ssize_t	r_bytes;
	char	buf[BUFFER_SIZE + 1];

	r_bytes = 1;
	while (!ft_strchr(buf, '\n') && r_bytes > 0)
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes < 0)
			return (0);
		buf[r_bytes] = '\0';
		tmp = ft_strjoin(tmp, buf);
		// if (!tmp)
		// {
		// 	free(tmp);
		// 	return (0);
		// }
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		rest[BUFFER_SIZE + 1];
	char			*ret;
	char			*tmp;
	ssize_t			len;
	ssize_t			i;
	ssize_t			j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = malloc(sizeof *tmp * (BUFFER_SIZE + 1));
	if (!tmp)
		return (0);
	// tmp[0] = '\0';
	// if (ft_strlen(rest) == 0)
	// 	rest[0] = '\0';
	// tmp = rest;
	tmp[0] = '\0';
	// printf("tmp is |%s|\n", tmp);
	tmp = read_line(tmp, fd);
	if (!tmp)
	{
		free(tmp);
		return (0);
	}
	// printf("rest2 |%s|\n", rest);
	len = ft_find_line(tmp);
	// printf("len %d\nc is |%c|\ntmp |%s|\n", len, tmp[len], tmp);
	ret = malloc(sizeof *ret * (len + 2));
	if (!ret)
		return (0);
	// ft_strlcpy(ret, tmp, len + 2);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		ret[i] = tmp[i];
		++i;
	}
	if (tmp[i])
	{
		ret[i] = '\n';
		++i;
		ret[i] = '\0';
	}
	// printf("ret1 |%s|\n", ret);
	j = 0;
	while (tmp[i + j] && j < BUFFER_SIZE)
	{
		rest[j] = tmp[i + j];
		++j;
	}
	rest[j] = '\0';
	// if (!rest[len - 1 + i])
	// {
	// 	free(rest);
	// 	return (0);
	// }
	
	// ft_strlcpy(rest, tmp + len + 1, i + 1);
	// ft_bzero(rest, len + 1 + i);
	if (tmp)
		free(tmp);
	// printf("ret2 |%s|\n", ret);
	return (ret);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	char	*ret;
// 	int		fd;
// 	size_t	i;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("OPEN ERROR\n");
// 		return (0);
// 	}
// 	i = 0;
// 	while (i < 7)
// 	{
// 		ret = get_next_line(fd);
// 		printf("str is %s", ret);
// 		free(ret);
// 		++i;
// 	}
// 	// ret = get_next_line(fd);
// 	// printf("str is %s", ret);
// 	// ret1 = get_next_line(fd);
// 	// printf("str is %s", ret1);
// 	// ret2 = get_next_line(fd);
// 	// printf("str is %s", ret2);
// 	return (0);
// }