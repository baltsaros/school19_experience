
int	ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 32) || (str[i] > 126))
			return (0);
		++i;
	}
	return (1);
}


#include <stdio.h>
int		main()
{
	char	*str;
	int		ret;

	str = "\a{aesz";
	ret = ft_str_is_printable(str);
	printf("return is %d\n", ret);
	return (0);
}



