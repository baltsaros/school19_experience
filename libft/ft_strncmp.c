#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n)
		++i;
	return (str1[i] - str2[i]);
}

int	main(void)
{
	char	str1[] = "abcd";
	char	str2[] = "abce";
	char	str3[] = "abcd";
	char	str4[] = "abce";

	printf("ret(ft) is %d\n", ft_strncmp(str1, str2, 5));
	printf("ret(ft) is %d\n", strncmp(str3, str4, 5));
	return (0);
}
