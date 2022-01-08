#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*dest;

	dest = (char *)s;
	while (n > 0 && *dest)
	{
		*dest = c;
		++dest;
		--n;
	}
	return (s);
}

// int		main(void)
// {
// 	char	s[] = "hello world";
// 	char	*ret;
// 	char	s2[] = "hello world";
// 	char	*ret2;


// 	ret = ft_memset(s + 3, '$', 5);
// 	ret2 = memset(s2 + 3, '$', 5);
// 	printf("return(ft) is '%s'\n", ret);
// 	printf("return(or) is '%s'\n", ret2);
// 	return (0);
// }