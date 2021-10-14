#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}

int		main()
{
	char	dest[] = "des";
	char	src[] = "source";
	unsigned int	n;

	printf("dest is %s\n", dest);
	printf("sizeof DEST is %lu\n", sizeof(dest));
	ft_strncpy(dest, src, 5);
	printf("dest2 is %s\n", dest);
	printf("sizeof2 DEST is %lu\n", sizeof(dest));
}
