#include <stdio.h>

int		check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || (base[i] < 33
			|| base[i] > 126))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int		check_str(char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		++i;
	}
	return (sign * i);
}

int		check_str_base(char *base, char c)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	int		sign;
	int		n;
	int		size_b;

	i = check_str(str);
	if (check_base(base) == 0)
		return (0);
	sign = 1;
	if (i < 0)
	{
		i = -i;
		sign = -1;
	}
	j = 0;
	n = 0;
	size_b = 0;
	while (base[size_b])
		++size_b;
	while (str[i + j])
	{
		n = n * size_b + check_str_base(base, str[i + j]);
		++j;
	}
	return (n * sign);
}

int	main(void)
{
	printf("1: %d\n", ft_atoi_base("123", "0123456789"));
	printf("2: %d\n", ft_atoi_base("   +---2147483648", "0123456789"));
	printf("3: %d\n", ft_atoi_base("   +----2147483647", "0123456789"));
	printf("4: %d\n", ft_atoi_base("   +----2147483647", "012345 6789"));
	printf("5: %d\n", ft_atoi_base("aabbcc", "abc"));
	printf("6: %d\n", ft_atoi_base("aabbcc", "aabc"));
	printf("7: %d\n", ft_atoi_base("aabbcc", ""));
	printf("8: %d\n", ft_atoi_base("", ""));
	printf("9: %d\n", ft_atoi_base("", "abc"));
	printf("10: %d\n", ft_atoi_base("\n  ++---aabbcc", "abc"));
	printf("11: %d\n", ft_atoi_base("12x", "0123456789"));
	printf("12: %d\n", ft_atoi_base("xxx", "0123456789"));
	printf("13: %d\n", ft_atoi_base("aa", "0123456789abcdef"));
	printf("\n");
	return 0;
}
