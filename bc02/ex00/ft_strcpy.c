
char	*ft_strcpy(char *dest, char *src)
{
	int j;

	j = 0;
	while (src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
}

/*
#include <stdio.h>
int		main()
{
	char	dest[] = "destin";
	char	src[] = "source";
	*ft_strcpy(&dest, &src);
	printf("source %s\n", src);
	printf("destination %s\n", dest);
	return (0);
}
*/