#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		++i;
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char	str1[] = "abcd";
	char	str2[] = "abcz";
	char	str3[] = "abcd";
	char	str4[] = "abcz";

	printf("ret(ft) is %d\n", ft_strncmp(str1, str2, 5));
	printf("ret(or) is %d\n", strncmp(str3, str4, 5));
	return (0);
}
