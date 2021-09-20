#include <stdlib.h> 
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		size;

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

#include <stdio.h>
#include <string.h>
int		main()
{
	char	src[] = "String to copy";

	printf("dest is %s\n", ft_strdup(src));
	return (0);
}