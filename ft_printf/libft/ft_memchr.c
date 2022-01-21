/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:31:25 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/13 12:33:55 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	x;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	x = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == x)
			return ((void *)s + i);
		++i;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char buffer[] = {0, 1, 2 ,3 ,4 ,5};
// 	int		c;
// 	char	*ret;
// 	const char buffer2[] = {0, 1, 2 ,3 ,4 ,5};
// 	char	*ret2;

// 	c = 'e';
// 	ret = ft_memchr(buffer, 2 + 256, 6);
// 	if (NULL == ret)
// 		printf("C was not found. Ret(ft) is '%s'\n", ret);
// 	else
// 		printf("C was found. Ret(ft) is '%s'\n", ret);
// 	ret2 = memchr(buffer, 2 + 256, 6);
// 	if (NULL == ret2)
// 		printf("C was not found. Ret(or) is '%s'\n", ret2);
// 	else
// 		printf("C was found. Ret(or) is '%s'\n", ret2);
// 	return (0);
// }