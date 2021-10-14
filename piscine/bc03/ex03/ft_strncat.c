#include <stdio.h>
#include <string.h>

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

	j = 0;
	size_d = ft_strlen(dest);
	while (src[j] && j < nb)
	{
		dest[size_d] = src[j];
		++j;
		++size_d;
	}
	dest[size_d] = '\0';
	return (dest);
}

int	main()
{
	char	dest[] = "hello";
	char	src[] = " worldabcd";
	char	dest2[] = "hello";
	char	src2[] = " worldabcd";
	unsigned int	nb;

	nb = 5;
	printf("initial dest is %s\n", dest2);
	printf("dest(cat) is %s\n", strncat(dest2, src2, nb));
	printf("dest(ft) is %s\n", ft_strncat(dest, src, nb));
}
