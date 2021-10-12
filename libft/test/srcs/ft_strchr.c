#include <stdio.h>

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (char *)str + i;
		++i;
	}
	return (NULL);
}
