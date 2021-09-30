#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 97) || (str[i] > 122))
			return(0);
		++i;
	}
	return (1);
}

int	main()
{
	char	*str;
	int		ret;

	str = "aesz";
	ret = ft_str_is_lowercase(str);
	printf("return is %d\n", ret);
	return (0);
}
