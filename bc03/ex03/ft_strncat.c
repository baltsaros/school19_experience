int	ft_strlen(char *dest)
{
	int		i;

	i = 0;
	while (dest[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	j;
	unsigned int	size_d;
	unsigned int	size_s;

	j = 0;
	size_d = ft_strlen(dest);
	size_s = ft_strlen(src);
	while (src[j] && j < nb)
	{
		dest[size_d] = src[j];
		++j;
		++size_d;
	}
	dest[size_d] = '\0';
	return (dest);
}


#include <stdio.h>
#include <string.h>
int	main()
{
	char	dest[] = "hello";
	char	dest2[] = "hello";
	char	src[] = " worldabcd";
	char	src2[] = " worldabcd";
	unsigned int	nb;

	nb = 8;
	printf("initial dest is %s\n", dest);
	ft_strncat(dest, src, nb);
	printf("dest(ft) is %s\n", dest);
	printf("dest(ft) is %s\n", strncat(dest2, src2, nb));
}
