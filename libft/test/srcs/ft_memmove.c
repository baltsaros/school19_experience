#include <stdio.h>
#include <string.h>

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
