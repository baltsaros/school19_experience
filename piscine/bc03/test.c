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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	size_s;
	unsigned int	size_d;
	unsigned int	size_d2;

	j = 0;
	size_s = ft_strlen(src);
	size_d = ft_strlen(dest);
	size_d2 = size_d;
	// if (size_d2 < size)
	// {
	// 	while (size_d2 < size)
	// 	{
	// 		dest[size_d2 + 1] = '\0';
	// 		++size_d2;
	// 	}
	// }
	while (src[j] != '\0' && j < size)
	{
		dest[size_d] = src[j];
		++size_d;
		++j;
	}
	while (j < size)
	{
		dest[size_d] = '\0';
		++size_d;
		++j;
	}
	return (ft_strlen(dest));
}

#include <stdio.h>
#include <string.h>
int	main()
{
	char	dest[] = "hello";
	char	src[] = " world";
	unsigned int	size;
	unsigned int	ret;

	size = 5;
	printf("dest size is %u\n", ft_strlen(dest));
	printf("src size is %u\n", ft_strlen(src));
	ret = ft_strlcat(dest, src, size);
	printf("ret(ft) is %u\n", ret);
	printf("new dest is %s\n", dest);
	return (0);
}
