/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:34:13 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/13 13:01:14 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && len > i)
	{
		j = 0;
		while ((big[i + j] == little[j]) && (len > i + j))
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			++j;
		}
		++i;
	}
	return (0);
}

// int	main(void)
// {
// 	char	big[] = "aaabcabcd";
// 	char	little[] = "cd";
// 	char	*ret;
// 	char	big2[] = "aaabcabcd";
// 	char	little2[] = "cd";
// 	char	*ret2;

// 	ret = ft_strnstr(big, little, 8);
// 	if (ret == NULL)
// 		printf("Little(ft) was not found!\n");
// 	else
// 		printf("Little(ft) was found! Return is '%s'!\n", ret);
// 	ret2 = strnstr(big2, little2, 8);
// 	if (ret2 == NULL)
// 		printf("Little(or) was not found!\n");
// 	else
// 		printf("Little(or) was found! Return is '%s'!\n", ret2);
// 	return (0);
// }