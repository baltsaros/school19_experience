#include <stdio.h>

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		n;

	i = 0;
	sign = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		++i;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + str[i] - '0';
		++i;
	}
	return (sign * n);
}

int	main()
{
	char	str[] = "  \t--+-+0234ab567";
	char	str2[] = "  --+-+\v0234ab567";
	char	str3[] = "  ---+-+50234ab567";

	printf("%s\n", str);
	printf("%d\n", ft_atoi(str));
	printf("%s\n", str2);
	printf("%d\n", ft_atoi(str2));
	printf("%s\n", str3);
	printf("%d\n", ft_atoi(str3));
	return (0);
}
