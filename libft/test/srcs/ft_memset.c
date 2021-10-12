#include <stdio.h>
#include <string.h>

void	*ft_memset(void *dest, int ch, size_t n)
{
	char	*dest_ch;

	dest_ch = (char *)dest;
	while (n > 0 && *dest_ch)
	{
		*dest_ch = ch;
		++dest_ch;
		--n;
	}
	return (dest_ch);
}
