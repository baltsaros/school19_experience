#include <stdio.h>

int	ft_strlen(char *dest)
{
	int		i;

	i = 0;
	while (dest[i])
		++i;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	i;

	len_d = 0;
	while (dest[len_d])
		++len_d;
	len_s = 0;
	while (src[len_s])
		++len_s;
	i = 0;
	while (src[i] && (len_d + i < size - 1))
	{
		dest[len_d + i] = src[i];
		++i;
	}
	dest[len_d + i] = '\0';
	return (len_d + len_s);
}

int	main()
{
	char	dest[10] = "Hello";
	char	src[8] = " world!";
	unsigned int	size;
	unsigned int	ret;

	size = 10;
	printf("dest len is %u\n", ft_strlen(dest));
	printf("src len is %u\n", ft_strlen(src));
	ret = ft_strlcat(dest, src, size);
	printf("ret is %u, buffer size is %u, new dest is '%s'\n", ret, size, dest);
	return (0);
}
