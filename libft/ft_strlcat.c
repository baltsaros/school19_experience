#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_d = 0;
	while (dst[len_d])
		++len_d;
	len_s = 0;
	while (src[len_s])
		++len_s;
	i = 0;
	while (src[i] && (len_d + i < size - 1))
	{
		dst[len_d + i] = src[i];
		++i;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}

int	main(void)
{
	char	dest[] = "Meat is ";
	char	src[] = "back on the menu, boys";
	size_t	ret;

	ret = ft_strlcat(dest, src, 31);
	printf("ret is %ld, dest is '%s'\n", ret, dest);
	return (0);
}
