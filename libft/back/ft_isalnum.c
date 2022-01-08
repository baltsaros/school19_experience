#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 &&
		c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	ret;

// 	ret = ft_isalnum('0');
// 	printf("for '0' return is %d\n", ret);
// 	ret = ft_isalnum('9');
// 	printf("for '9' return is %d\n", ret);
// 	ret = ft_isalnum('a');
// 	printf("for 'a' return is %d\n", ret);
// 	ret = ft_isalnum('z');
// 	printf("for 'z' return is %d\n", ret);
// 	ret = ft_isalnum('A');
// 	printf("for 'A' return is %d\n", ret);
// 	ret = ft_isalnum('Z');
// 	printf("for 'Z' return is %d\n", ret);
// 	ret = ft_isalnum(' ');
// 	printf("for ' ' return is %d\n", ret);
// 	ret = ft_isalnum(')');
// 	printf("for ')' return is %d\n", ret);
// 	return (0);
// }