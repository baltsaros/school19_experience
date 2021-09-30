#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 65) || (str[i] > 90))
			return (0);
		++i;
	}
	return (1);
}

int	main()
{
	char	*str;
	int		ret;

	str = "1AESZ";
	ret = ft_str_is_uppercase(str);
	printf("return is %d\n", ret);
	return (0);
}
