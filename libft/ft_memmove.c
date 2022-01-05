#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_ch;
	char	*src_ch;
	unsigned int	i;

	if (dest == 0 && src == 0)
		return (0);
	dest_ch = (char *)dest;
	src_ch = (char *)src;
	i = 0;
	if (dest_ch > src_ch)
	{
		while (n > 0)
		{
			dest_ch[n - 1] = src_ch[n - 1];
			--n;
		}
	}
	else
	{
		while (i < n)
		{
			dest_ch[i] = src_ch[i];
			++i;
		}
	}
	return (dest);
}

int		main(void)
{
	char	src[] = " worldHello";
	// char	src1[] = "world world";
	// char	dest1[] = "Hello";
	char	*ret;

	ret = ft_memmove(src, src + 3, 5);
	// ret = memmove(src, src + 3, 5);
	// ret = ft_memmove(src + 3, src, 2);
	// ret = memmove(src + 3, src, 2);
	// ret = ft_memmove(dest1, src1, 5);
	// ret = memmove(dest1, src1, 5);
	// ret = ft_memmove(src1, dest1, 5);
	// ret = memmove(src1, dest1, 5);
	printf("new dest: %s\n", ret);
	return (0);
}
