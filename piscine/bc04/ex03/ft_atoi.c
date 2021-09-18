/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:11:10 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/18 08:11:11 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_sign(char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		++i;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			++sign;
		++i;
	}
	if (sign % 2 != 0)
		return (-i);
	else
		return (i);
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

/*
#include <stdio.h>
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
*/
