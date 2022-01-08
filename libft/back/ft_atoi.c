#include "libft.h"

int	ft_atoi(const char *str)
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

// int	main(void)
// {
// 	char	str[] = "  \t--+-+0234ab567";
// 	char	str2[] = "  --+-+\v0234ab567";
// 	char	str3[] = "  ---+-+50234ab567";
// 	char	str4[] = "1234ab567";
// 	int		ret;

// 	ret = ft_atoi("  \t--+-+0234ab567");
// 	printf("Test 1 %s\n%d\n", str, ret);
// 	ret = ft_atoi("  --+-+\v0234ab567");
// 	printf("Test 2 %s\n%d\n", str2, ret);
// 	ret = ft_atoi("  ---+-+50234ab567");
// 	printf("Test 3 %s\n%d\n", str3, ret);
// 	ret = ft_atoi("1234ab567");
// 	printf("Test 4 %s\n%d\n", str4, ret);
// 	return (0);
// }
