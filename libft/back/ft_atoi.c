/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:28:57 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 15:43:41 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i] == '-');
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
// 	char	str5[] = "+-54";
// 	char	str6[] = "-+48";
// 	char	str7[] = "--47";
// 	char	str8[] = "++47";
// 	int		ret;
// 	int		ret2;

// 	ret = ft_atoi("  \t--+-+0234ab567");
// 	printf("FT: Test 1 %s\n%d\n", str, ret);
// 	ret2 = atoi("  \t--+-+0234ab567");
// 	printf("OR: Test 1 %s\n%d\n", str, ret2);
// 	ret = ft_atoi("  --+-+\v0234ab567");
// 	printf("FT: Test 2 %s\n%d\n", str2, ret);
// 	ret2 = atoi("  --+-+\v0234ab567");
// 	printf("OR: Test 2 %s\n%d\n", str2, ret2);
// 	ret = ft_atoi("  ---+-+50234ab567");
// 	printf("Test 3 %s\n%d\n", str3, ret);
// 	ret = ft_atoi("1234ab567");
// 	printf("Test 4 %s\n%d\n", str4, ret);
// 	ret = ft_atoi("+-54");
// 	printf("FR: Test 5 %s\n%d\n", str5, ret);
// 	ret2 = atoi("+-54");
// 	printf("OR: Test 5 %s\n%d\n", str5, ret2);
// 	ret = ft_atoi("-+48");
// 	printf("FT: Test 6 %s\n%d\n", str6, ret);
// 	ret2 = atoi("-+48");
// 	printf("OR: Test 6 %s\n%d\n", str6, ret2);
// 	ret = ft_atoi("--47");
// 	printf("FT: Test 7 %s\n%d\n", str7, ret);
// 	ret2 = atoi("--47");
// 	printf("OR: Test 7 %s\n%d\n", str7, ret2);
// 	ret = ft_atoi("++47");
// 	printf("FT: Test 8 %s\n%d\n", str8, ret);
// 	ret2 = atoi("++47");
// 	printf("OR: Test 8 %s\n%d\n", str8, ret2);
// 	return (0);
// }