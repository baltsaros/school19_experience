#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	int			i;
	int			size;

	size = 0;
	while (src[size])
		++size;
	dest = (char *)malloc(sizeof(*src) * (size + 1));
	if (NULL == dest)
		return NULL;
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
