#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		main()
{
	char	dest[] = "destination";
	char	src[] = "so";
	
	printf("dest before %s\n", dest);
	ft_strcpy(dest, src);
	printf("src %s\n", src);
	printf("dest after %s\n", dest);
	return (0);
}
