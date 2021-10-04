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
	i = 0;
	while (i < n)
	{
		dest_ch[i] = tmp[i];
		++i;
	}
	return (dest);
}

int		main(void)
{
	char	src[] = " worldHello";

	ft_memmove(src + 3, src, 5);
	// memmove(src + 3, src, 5);
	printf("dest is: %s\n", src);
	return (0);
}
