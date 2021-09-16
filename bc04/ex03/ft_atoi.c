int	ft_sign(char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	while (str[i] == ' ')
		++i;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i]== '-')
			++sign;
		++i;
	}
	if (sign % 2 != 0)
		return (-i);
	else
		return(i);
}

int	ft_atoi(char *str)
{
	int		j;
	int		sign;
	int		n;

	j = ft_sign(str);
	n = 0;
	sign = 1;
	if (j < 0)
	{
		j = -j;
		sign = -1;
	}
	while (str[j] >= 48 && str[j] <= 57)
	{
		n = n * 10 + str[j] - '0';
		++j;
	}
	return (sign * n);
}

#include <stdio.h>
int	main()
{
	char	str[] = "  --+-+0234ab567";

	printf("%s\n", str);
	printf("%d\n", ft_atoi(str));
	return (0);
}
