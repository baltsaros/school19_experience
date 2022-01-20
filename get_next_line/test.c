
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*ret;
	static char		buffer[BUFFER_SIZE];
	ssize_t			r_bytes;
	static ssize_t	i;
	ssize_t			j;

	if (fd < 0)
		return (0);
	r_bytes = read(fd, buffer, BUFFER_SIZE);
	if (!r_bytes)
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		++i;
	++i;
	ret = malloc(sizeof *ret * i);
	if (!ret)
		return (0);
	j = 0;
	while (j < i - 1)
	{
		ret[j] = buffer[j];
		if ((j + 1 == i - 1) && ret[j])
			ret[j] = '\n';
		++j;
	}
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