/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:34:18 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:52:58 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	while (i > 0)
	{
		if (s[i - 1] == c)
			return ((char *)s + i - 1);
		--i;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "Hello world!";
// 	char	c;
// 	char	*ret;
// 	char	str2[] = "Hello world!";
// 	char	*ret2;

// 	c = 'o';
// 	ret = ft_strrchr(str, c);
// 	if (NULL == ret)
// 		printf("C was not found. Ret(ft) is '%s'\n", ret);
// 	else
// 		printf("C was found. Ret(ft) is '%s'\n", ret);
// 	ret2 = strrchr(str2, c);
// 	if (NULL == ret2)
// 		printf("C was not found. Ret(or) is '%s'\n", ret2);
// 	else
// 		printf("C was found. Ret(or) is '%s'\n", ret2);
// 	return (0);
// }