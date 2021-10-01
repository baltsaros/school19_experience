#include <stdio.h>

int	ft_isascii(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 0 && str[i] <= 127)
			++i;
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
	char	*str;
	int		ret;

	str = "isascii";
	ret = ft_isascii(str);
	printf("return is %d\n", ret);
	return (0);
}
