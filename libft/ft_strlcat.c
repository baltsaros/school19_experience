#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	size_s;
	unsigned int	size_d;
	unsigned int	i;

	size_s = 0;
	while (src[size_s])
		++size_s;
	size_d = 0;
	while (dest[size_d])
		++size_d;
	i = 0;
	while (src[i] && (size_d + i < n - 1))
	{
		dest[size_d + i] = src[i];
		++i;
	}
	dest[size_d + i] = '\0';
	return (size_d + size_s);
}

int	main(void)
{
	char	dest[] = "This is ";
	char	src[] = "a potentially long string";
	unsigned int	ret;

	ret = ft_strlcat(dest, src, 16);
	printf("ret is %d, dest is '%s'\n", ret, dest);
	return (0);
}
