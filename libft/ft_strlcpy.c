#include "libft.h"

size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t n)
{
	unsigned int	i;
	unsigned int	size_s;

	size_s = 0;
	while (src[size_s])
		++size_s;
	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (size_s);
}

int	main(void)
{
	char	dest[6];
	char	src[13] = "Hello world!";
	unsigned int	ret;

	ret = ft_strlcpy(dest, src, 5);
	// ret = strlcpy(dest, src, 10);
	printf("src is '%s', dest is '%s', ret is %d\n", src, dest, ret);
	return (0);
}
