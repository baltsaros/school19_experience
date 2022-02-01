#include "get_next_line.h"

static size_t	ft_find_line(char	*input)
{
	size_t	i;

	i = 0;
	while (input[i] && i < BUFFER_SIZE)
	{
		++i;
		if (input[i] == '\n')
			return (i);
	}
	return (0);
}



char	*get_next_line(int fd)
{
	static char		rest[BUFFER_SIZE];
	char			*ret;
	char			buf[BUFFER_SIZE];
	ssize_t			r_bytes;
	ssize_t			len;

	if (fd < 0)
		return (0);
	// printf("%d\n", ft_find_line(rest));
	if (ft_find_line(rest))
	{
		len = ft_find_line(rest) + 1;
		ret = malloc(sizeof *ret * (len + 1));
		if (!ret)
			return (0);
		ft_strlcpy(ret, rest, len + 1);
		ft_strlcpy(buf, rest + len, len + 1);
		ft_bzero(rest, BUFFER_SIZE);
		ft_strlcpy(rest, buf, BUFFER_SIZE);
		return (ret);
	}
	r_bytes = read(fd, buf, BUFFER_SIZE);
	if (r_bytes < 0)
		return (0);
	len = ft_find_line(buf) + 1;
	// printf("len %d, read %d\n", len, r_bytes);
	ret = malloc(sizeof *ret * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, buf, len + 1);
	ft_strlcpy(rest, buf + len, BUFFER_SIZE);
	// printf("%s", rest);
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
	while (i < 4)
	{
		ret = get_next_line(fd);
		printf("str is %s", ret);
		free(ret);
		++i;
	}
	return (0);
}