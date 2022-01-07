#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_ch;
	char	*src_ch;
	char	tmp[n];
	size_t	i;

	dest_ch = (char *)dest;
	src_ch = (char *)src;
	i = 0;
	while (i < n)
	{
		tmp[i] = src_ch[i];
		++i;
	}
	while (0 < i)
	{
		dest_ch[i - 1] = tmp[i - 1];
		--i;
	}
	return (dest);
}

int		main(void)
{
	// char	src[] = " worldHello";
	char	src[] = "world world";
	char	src2[] = "world world";
	char	dest[] = "Hello";
	char	dest2[] = "Hello";
	char	*ret;
	char	*ret2;

	// ret = ft_memmove(src, src + 3, 5);
	// ret2 = memmove(src2, src2 + 3, 5);
	ret = ft_memmove(src + 3, src, 5);
	ret2 = memmove(src2 + 3, src, 5);
	// ret = ft_memmove(dest, src, 5);
	// ret2 = memmove(dest2, src2, 5);
	// ret = ft_memmove(src, dest, 5);
	// ret2 = memmove(src2, dest2, 5);
	printf("new dest(ft): %s\n", ret);
	printf("new dest(or): %s\n", ret2);
	return (0);
}
