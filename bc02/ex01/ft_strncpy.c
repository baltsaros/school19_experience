char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		j;

	j = 0;
	while (src[j] && j < n)
	{
		dest[j] = src[j];
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		++j;
	}
	return (dest);
}


#include <stdio.h>
int		main()
{
	char	dest[] = "destination";
	char	src[] = "source";
	int		n;

	n = ft_strlen(src);
	printf("strlen SRC is %d\n", n);
	printf("sizeofsrc is %lu\n", sizeof(src));
	printf("dest is %s\n", dest);
	printf("sizeof DEST is %lu\n", sizeof(dest));
	*ft_strncpy(dest, src, n);
	printf("dest2 is %s\n", dest);
	printf("sizeof2 DEST is %lu\n", sizeof(dest));
}
