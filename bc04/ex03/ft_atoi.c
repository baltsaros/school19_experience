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
	int		i;
	int		j;
	int		sign;
	int		tab;

	i = 0;
	tab = 0;
	if (ft_sign(str) >= 0)
	{
		j = ft_sign(str);
		sign = 1;
	}
	else
	{
		j = -ft_sign(str);
		sign = -1;
	}
	while (str[j] >= 48 && str[j] <= 57)
	{
		tab = tab * 10 + str[j] - '0';
		++i;
		++j;
	}
	tab = tab * sign;
	return (tab);
}

#include <stdio.h>
int	main()
{
	char	str[] = "  ---+--+0234ab567";

	printf("%s\n", str);
	printf("%d\n", ft_atoi(str));
	return (0);
}
