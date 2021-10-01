#include <stdio.h>

int	ft_isascii(int ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	else
		return (0);
}

int	main(void)
{
	int	ret;

	ret = ft_isascii('a');
	printf("return is %d\n", ret);
	ret = ft_isascii('\0');
	printf("return is %d\n", ret);
	ret = ft_isascii(' ');
	printf("return is %d\n", ret);
	ret = ft_isascii('~');
	printf("return is %d\n", ret);
	return (0);
}
