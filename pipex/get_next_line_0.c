#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"

static size_t	ft_check_set(char *s, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] == set[j])
		{
			if (!set[j + 1])
				return (i);
			++j;
		}
		++i;
	}
	return (i);
}

static size_t	ft_check(char *s, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] == set[j])
		{
			if (!set[j + 1])
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

static char		*ft_strjoin_free(char *line, char *buf, char *limiter)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*unis;

	l = ft_check_set(buf, limiter);
	unis = ft_calloc(ft_strlen(line) + l + 1, sizeof(unis));
	if (!unis)
		error_check(-1, "In Calloc ", 11);
	i = 0;
	while (line[i])
	{
		unis[i] = line[i];
		++i;
	}
	j = 0;
	while (j < l)
	{
		unis[i + j] = buf[j];
		++j;
	}
	free(line);
	return (unis);
}

int			get_next_line(char **line, char *limiter)
{
	char	buf[1000];
	int		check;
	ssize_t	r_bytes;

	*line = ft_calloc(1, sizeof(char));
	if (!line | !*line | !limiter)
		error_check(-1, "In gnl ", 8);
	r_bytes = 1;
	check = 0;
	while ((r_bytes = read(0, buf, 1000)) > 0 && !check)
	{
		if (r_bytes < 0)
		{
			free(*line);
			error_check(r_bytes, "In gnl_read ", 13);
		}
		buf[r_bytes] = 0;
		check = ft_check(buf, limiter);
		*line = ft_strjoin_free(*line, buf, limiter);
	}
	return (r_bytes);
}

#include <stdio.h>
int		main(void)
{
	char	*line;
	int		ret;

	ret = get_next_line(&line, "five");
	printf("ret is %d\n", ret);
	printf("line is |%s|\n", line);
	return (0);
}