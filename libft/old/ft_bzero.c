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

int	main(void)
{
	char	str[] = "hello world";

	ft_bzero(str+4, 5);
	printf("new str is %s\n", str);
	return (0);
}
