/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:32:38 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/12 12:30:47 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*dest;

	dest = (char *)s;
	while (n > 0)
	{
		*dest = c;
		++dest;
		--n;
	}
	return (s);
}

// int	main(void)
// {
// 	char	*b1 = (char*)malloc(sizeof(char) * (20 + 1));
// 	char	*b2 = (char*)malloc(sizeof(char) * (20 + 1));
// 	char	*ret;
// 	char	*ret2;

// 	*b1 = 0;
// 	*b2 = 0;
// 	ret = memset(b1, '\5', 20);
// 	ret2 = ft_memset(b2, '\5', 20);
// 	printf("return(or) is '%s'\n", ret);
// 	printf("return(ft) is '%s'\n", ret2);
// }

// int		main(void)
// {
// 	char	s[] = "hello world";
// 	char	*ret;
// 	char	s2[] = "hello world";
// 	char	*ret2;

// 	ret = ft_memset(s, 'A', 5);
// 	ret2 = memset(s2, 'A', 5);
// 	printf("return(ft) is '%s'\n", ret);
// 	printf("return(or) is '%s'\n", ret2);
// 	return (0);
// }