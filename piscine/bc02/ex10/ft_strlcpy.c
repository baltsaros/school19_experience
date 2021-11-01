#include <stdio.h>
#include <bsd/string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	size_s;

	size_s = 0;
	while (src[size_s])
		++size_s;
	i = 0;
	while (i < size && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (size_s);
}

int	main(void)
{

	char	dest[6] = "world";
	char	src[13] = "Hello world!";
	// char	dest1[6] = "world";
	// char	src1[13] = "Hello world!";
	unsigned int	ret;

	ret = ft_strlcpy(dest, src, 5);
	printf("ret is %d, dest is %s\n", ret, dest);
	// ret = strlcpy(dest1, src1, 5);
	// printf("ret is %d, dest is %s\n", ret, dest1);
	return (0);
}
