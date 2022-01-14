#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*ret;
	ssize_t	r_bytes;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	if (fd < 0)
		return (0);
	buffer = malloc(sizeof *buffer * BUFFER_SIZE);
	if (!buffer)
		return (0);
	r_bytes = read(fd, buffer, BUFFER_SIZE);
	if (!r_bytes)
		return (0);
	while (buffer[i]&& buffer[i] != '\n')
		++i;
	ret = malloc(sizeof *ret * i);
	if (!ret)
		return (0);
	j = 0;
	while (j < i)
	{
		ret[j] = buffer[j];
		++j;
	}
	return (ret);
}