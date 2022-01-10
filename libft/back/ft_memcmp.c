/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:31:30 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:31:31 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	const char		*str1;
	const char		*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < (n - 1) && str1[i] == str2[i])
		++i;
	return (str1[i] - str2[i]);
}

// int	main(void)
// {
// 	const char	buffer1[] = "\0\0\0cd";
// 	const char	buffer2[] = "\0\0\0zd";
// 	const char	buffer3[] = "\0\0\0cd";
// 	const char	buffer4[] = "\0\0\0zd";

// 	printf("ret(ft) is %d\n", ft_memcmp(buffer1, buffer2, 4));
// 	printf("ret(or) is %d\n", memcmp(buffer3, buffer4, 4));
// 	return (0);
// }