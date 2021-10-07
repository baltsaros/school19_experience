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

#include <stdio.h>
#include <string.h>
int		main()
{
	char	src[] = "String to copy";
	char	src2[] = "String to copy";

	printf("dest(ft) is %s\n", ft_strdup(src));
	printf("dest(dup) is %s\n", strdup(src2));
	return (0);
}
