#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	size_s;

	size_s = 0;
	while (src[size_s])
		++size_s;
	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (size_s);
}
