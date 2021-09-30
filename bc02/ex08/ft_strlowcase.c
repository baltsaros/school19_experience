#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 65) && (str[i] <= 90))
			str[i] = str[i] + 32;
		++i;
	}
	return (str);
}

int	main()
{
	char	str[] = "1AESZ";

	printf("first %s\n", str);
	ft_strlowcase(str);
	printf("third %s\n", str);
	return (0);
}
