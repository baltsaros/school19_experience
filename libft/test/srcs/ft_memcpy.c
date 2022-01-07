#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_ch;
	char	*dest_ch;
	
	if (dest == src)
		return dest;
	src_ch = (char *)src;
	dest_ch = (char *)dest;
	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	while (n > i)
	{
		dest_ch[i] = src_ch[i];
		++i;
	}
	return (dest);
}

// int		main(void)
// {
// 	char	dest[] = " worldHello";
// 	char	dest2[] = " worldHello";
// 	char	src[] = "world";
// 	char	src2[] = "world";
// 	int		n = 5;
// 	char	*ret;
// 	char	*ret2;

// 	// ret = ft_memcpy(dest, dest, n);
// 	// ret2 = memcpy(dest2, dest2, n);
// 	ret = ft_memcpy(dest, src, n);
// 	ret2 = memcpy(dest2, src2, n);
// 	// ret = ft_memcpy(src, src + 3, n);
// 	// ret2 = memcpy(src2, src2 + 3, n);
// 	// ret = ft_memcpy(src2 + 3, src2, n);
// 	// ret2 = memcpy(src2 + 3, src2, n);
// 	printf("new dest(ft): %s\n", ret);
// 	printf("new dest(or): %s\n", ret2);
// 	return (0);
// }