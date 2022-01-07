#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (char *)s + i;
		++i;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "Hello world!";
// 	char	str2[] = "Hello world!";
// 	char	c;
// 	char	*ret;
// 	char	*ret2;

// 	c = 's';
// 	ret = ft_strchr(str, c);
// 	if (NULL == ret)
// 		printf("C was not found. Ret(ft) is '%s'\n", ret);
// 	else
// 		printf("C was found. Ret(ft) is '%s'\n", ret);
// 	ret2 = strchr(str2, c);
// 	if (NULL == ret2)
// 		printf("C was not found. Ret(or) is '%s'\n", ret2);
// 	else
// 		printf("C was found. Ret(or) is '%s'\n", ret2);
// 	return (0);
// }