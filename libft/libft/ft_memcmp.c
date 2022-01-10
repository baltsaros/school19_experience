/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:31:30 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 16:29:58 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*str1;
	const char	*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < (n - 1) && str1[i] == str2[i])
		++i;
	return (str1[i] - str2[i]);
}

// int	main(void)
// {
// 	const char	buffer1[] = "t\200a";
// 	const char	buffer2[] = "t\0a";
// 	const char	buffer3[] = "t\200a";
// 	const char	buffer4[] = "t\0a";

// 	printf("ret(ft) is %d\n", ft_memcmp(buffer1, buffer2, 3));
// 	printf("ret(or) is %d\n", memcmp(buffer3, buffer4, 3));
// 	return (0);
// }