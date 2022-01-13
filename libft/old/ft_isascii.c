#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int	main(void)
{
	int	ret;

	ret = ft_isascii('ç');
	printf("for 'ç' return is %d\n", ret);
	return (0);
}
