#include <stdio.h>

int	ft_isascii(int ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
		return (1);
	else
		return (0);
}

int	main(void)
{
	int	ret;

	ret = ft_isascii('A');
	printf("return is %d\n", ret);
	ret = ft_isascii('Z');
	printf("return is %d\n", ret);
	ret = ft_isascii('a');
	printf("return is %d\n", ret);
	ret = ft_isascii('z');
	printf("return is %d\n", ret);
	ret = ft_isascii('1');
	printf("return is %d\n", ret);
	ret = ft_isascii(' ');
	printf("return is %d\n", ret);
	return (0);
}
