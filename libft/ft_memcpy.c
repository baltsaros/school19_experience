#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char	*src_ch;
	char	*dest_ch;
	
	if (dest == src)
		return dest;
	src_ch = (char *)src;
	dest_ch = (char *)dest;
	// if (src_ch == 0)
	// 	return (0);
	i = 0;
	while (n > i)
	{
		dest_ch[i] = src_ch[i];
		++i;
	}
	return (dest);
}

int		main(void)
{
	char	dest[] = " worldHello";
	char	src[] = "";
	int		n = 5;

	ft_memcpy(dest, src, n);
	// memcpy(dest, src, n);
	// ft_memcpy(src, src + 3, n);
	// memcpy(src, src + 3, n);
	// ft_memcpy(src + 3, src, n);
	// memcpy(src + 3, src, n);
	printf("new dest: %s\n", dest);
	return (0);
}
