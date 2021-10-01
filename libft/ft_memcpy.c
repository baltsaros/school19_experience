#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned int	i;
	char	*src_ch;
	char	*dest_ch;
	
	src_ch = (char *)src;
	dest_ch = (char *)dest;
	i = 0;
	while (n > i && src_ch[i])
	{
		dest_ch[i] = src_ch[i];
		++i;
	}
	return (dest);
}

int		main(void)
{
	char	dest[] = "hello";
	char	src[] = "world";
	int		n = 5;

	ft_memcpy(dest, src, n);
	// memcpy(dest, src, n);
	printf("new dest: %s\n", dest);
	return (0);
}