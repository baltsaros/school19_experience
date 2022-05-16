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
