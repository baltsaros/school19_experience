#include "gnl_m.h"

// NOT GOOD SOLUTION; TOO COMPLEX AND MESS WITH RETURN

size_t	find_line(char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		++i;
	return (i);
}

int		*read_line(char **rest)
{
	char	*buf;
	ssize_t	r_bytes;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	r_bytes = 1;
	while (!ft_strchr(*rest, '\n') && r_bytes > 0)
	{
		r_bytes = read(0, buf, BUFFER_SIZE);
		if (r_bytes < 0)
		{
			free(buf);
			return (-1);
		}
		buf[r_bytes] = '\0';
		*rest = ft_strjoin_free(*rest, buf);
	}
	free(buf);
	return (r_bytes);
}

char	*copy_line(char *rest)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	if (!rest[0])
		return (rest);
	len = find_line(rest);
	tmp = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (i < len)
	{
		tmp[i] = rest[i];
		++i;
	}
	return (tmp);
}

char	*update_rest(char *rest)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	len = find_line(rest);
	if (!rest[len + 1])
	{
		free(rest);
		return (0);
	}
	i = 0;
	while(rest[len + 1])
		++i;
	tmp = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (rest[len + 1 + i])
	{
		tmp[i] = rest[len + 1 + i];
		++i;
	}
	free(rest);
	return (tmp);
}

int		get_next_line(char **line)
{
	static char	*rest;
	int			ret;

	if (BUFFER_SIZE <= 0)
		return (-1);
	ret = read_line(&rest);
	if (ret < 0)
		return (-1);
	*line = copy_line(rest);
	if (!(*line[0]))
	{
		free(rest);
		return (0);
	}
	rest = update_rest(rest);
	if (!rest)
		return (0);
	return (1);
}

#include <stdio.h>
int		main(void)
{
	char	*line;
	int		i;	int		ret;

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