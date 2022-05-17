#include "../include/minishell.h"

char	*ft_strndup(char const *str, size_t size)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(*dest) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

int	error_check(int input, char *str, int n)
{
	if (input < 0)
	{
		write(2, str, n);
		perror("something went wrong");
		exit (EXIT_FAILURE);
	}
	return (input);
}

char	*ft_strjoin_free(char *rest, char *buf)
{
	char	*unis;
	size_t	i;
	size_t	j;

	if (!rest || !buf)
		return (0);
	unis = malloc(sizeof(*unis) * (ft_strlen(rest) + ft_strlen(buf) + 1));
	if (!unis)
		return (0);
	i = 0;
	while (rest[i])
	{
		unis[i] = rest[i];
		++i;
	}
	j = 0;
	while (buf[j])
	{
		unis[i + j] = buf[j];
		++j;
	}
	unis[j + i] = '\0';
	free(rest);
	return (unis);
}

char	*ft_charjoin_free(char *line, char b)
{
	size_t	i;
	char	*unis;

	i = 0;
	while (line[i])
		++i;
	unis = malloc(sizeof(*unis) * (i + 2));
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
