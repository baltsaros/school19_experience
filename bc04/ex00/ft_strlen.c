int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}


#include <stdio.h>
int	main()
{
	char	str[] = "abcd";
	char	str2[] = "9876543210";
	char	str3[] = "";

	printf("str1 is %s\n", str);
	printf("strlen is %d\n", ft_strlen(str));
	printf("str2 is %s\n", str2);
	printf("strlen is %d\n", ft_strlen(str2));
	printf("str3 is %s\n", str3);
	printf("strlen is %d\n", ft_strlen(str3));
}
