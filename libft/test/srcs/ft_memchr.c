#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *buffer, int ch, size_t n)
{
	unsigned int	i;
	const char	*str;

	i = 0;
	str = buffer;
	while (i < n)
	{
		if (str[i] == ch)
			return (void *)buffer + i;
		++i;
	}
	return (NULL);
}
