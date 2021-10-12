#include <stdio.h>

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	while (i > 0)
	{
		if (str[i - 1] == ch)
			return (char *)str + i - 1;
		--i;
	}
	return (NULL);
}
