/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:34:09 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/11 10:38:21 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < (n - 1))
		++i;
	return (str1[i] - str2[i]);
}

int	main(void)
{
	printf("TEST 1\n");
	printf("ret(ft) is %d\n", ft_strncmp("salut", "salut", 5));
	printf("ret(or) is %d\n", strncmp("salut", "salut", 5));
	printf("TEST 2\n");
	printf("ret(ft) is %d\n", ft_strncmp("test", "testss", 7));
	printf("ret(or) is %d\n", strncmp("test", "testss", 7));
	printf("TEST 3\n");
	printf("ret(ft) is %d\n", ft_strncmp("testss", "test", 7));
	printf("ret(or) is %d\n", strncmp("testss", "test", 7));
	printf("TEST 4\n");
	printf("ret(ft) is %d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
	printf("ret(or) is %d\n", strncmp("abcdefgh", "abcdwxyz", 4));
	printf("TEST 5\n");
	printf("ret(ft) is %d\n", ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("ret(or) is %d\n", strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("TEST 6\n");
	printf("ret(ft) is %d\n", ft_strncmp("abcdefgh", "", 0));
	printf("ret(or) is %d\n", strncmp("abcdefgh", "", 0));
	printf("TEST 7\n");
	printf("ret(ft) is %d\n", ft_strncmp("test\200", "test\0", 6));
	printf("ret(or) is %d\n", strncmp("test\200", "test\0", 6));

	return (0);
}