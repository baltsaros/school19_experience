#include <stdio.h>

int	ft_isalnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 &&
			str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
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

	str = "hello0";
	ret = ft_isalnum(str);
	printf("return is %d\n", ret);
	return (0);
}