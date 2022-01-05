#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
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
	while (src[i] && (len_d + i < n - 1))
	{
		dest[len_d + i] = src[i];
		++i;
	}
	dest[len_d + i] = '\0';
	return (len_d + len_s);
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
