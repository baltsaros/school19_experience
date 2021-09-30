#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 48) || (str[i] > 57))
			return(0);
		++i;
	}
	return (1);
}

int	main()
{
	char	*str;
	int		ret;

	str = "1234";
	ret = ft_str_is_numeric(str);
	printf("return is %d\n", ret);
	return (0);
}