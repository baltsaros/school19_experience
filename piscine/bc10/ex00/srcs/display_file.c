#include <fcntl.h>
#include <unistd.h>
#include "display_file.h"

int		display_file(char *path)
{
	char	buf[ARRAY_SIZE];
	int		fd;
	int		r_bytes;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	r_bytes = read(fd, buf, ARRAY_SIZE);
	i = 0;
	if (r_bytes < 0)
		return (0);
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
