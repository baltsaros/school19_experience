#include <stdio.h>

void	ft_bzero(void *str, size_t n)
{
	char	*str_ch;

	str_ch = (char *)str;
	while (n > 0 && *str_ch)
	{
		*str_ch = '\0';
		++str_ch;
		--n;
	}
}
