#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str_ch;

	str_ch = (char *)s;
	while (n > 0 && *str_ch)
	{
		*str_ch = '\0';
		++str_ch;
		--n;
	}
}
