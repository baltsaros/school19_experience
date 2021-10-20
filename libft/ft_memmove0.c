#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_ch;
	char	*src_ch;
	char	tmp[n];
	unsigned int	i;

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
	char	src1[] = "world world";
	char	dest1[] = "Hello";
	char	*ret;

	// ft_memmove(src, src + 3, 5);
	// memmove(src, src + 3, 5);
	// ft_memmove(src + 3, src, 5);
	// memmove(src + 3, src, 5);
	// ret = ft_memmove(dest1, src1, 5);
	ret = memmove(dest1, src1, 5);
	// ret = ft_memmove(src1, dest1, 5);
	// ret = memmove(src1, dest1, 5);
	printf("new dest: %s\n", ret);
	return (0);
}
