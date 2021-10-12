#include <stdio.h>

int	ft_isprint(int ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	else
		return (0);
}

int	main(void)
{
	int	ret;

	ret = ft_isprint('a');
	printf("return is %d\n", ret);
	ret = ft_isprint('\0');
	printf("return is %d\n", ret);
	ret = ft_isprint(' ');
	printf("return is %d\n", ret);
	ret = ft_isprint('~');
	printf("return is %d\n", ret);
	return (0);
}
