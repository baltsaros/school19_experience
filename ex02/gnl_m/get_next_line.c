#include <unistd.h>
#include <stdlib.h>

char	*ft_strjoin_free(char *line, char b)
{
	size_t	i;
	char	*unis;

	i = 0;
	while (line[i])
		++i;
	unis = malloc(sizeof(unis) * (i + 2));
	if (!unis)
		return (0);
	i = 0;
	while (line[i])
	{
		unis[i] = line[i];
		++i;
	}
	unis[i] = b;
	unis[i + 1] = 0;
	free(line);
	return (unis);
}

int		get_next_line(char **line)
{
	char	buf[1];
	ssize_t	r_bytes;

	*line = malloc(sizeof(char));
	if (!line || *line)
		return (-1);
	*line[0] = 0;
	while ((r_bytes = read(0, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
		{
			break;
		}
		*line = ft_strjoin_free(*line, buf[0]);
	}
	free(buf);
	return (r_bytes);
}

#include <stdio.h>
int		main(void)
{
	char	*line;
	int		i;	
	int		ret;

	i = 0;
	while (i < 6)
	{
		ret = get_next_line(&line);
		printf("ret is %d\n", ret);
		printf("line is |%s|\n", line);
		++i;
	}
	return (0);
}