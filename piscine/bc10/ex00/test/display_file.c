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
	i = 0;
	while ((r_bytes = read(fd, buf, ARRAY_SIZE)) > 0);
	{
		if (r_bytes < 0)
			return (0);
		while (i < r_bytes)
		{
			write(1, &buf[i], 1);
			++i;
		}
	}
	buf[ARRAY_SIZE] = '\0';
	close(fd);
	return (1);
}