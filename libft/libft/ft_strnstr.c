/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:34:13 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/17 16:19:19 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && len > i)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (len > i + j))
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			++j;
		}
		++i;
	}
	return (0);
}

// int	main(void)
// {
// 	char	haystack[] = "aaabcabcd";
// 	char	needle[] = "cd";
// 	char	*ret;
// 	char	haystack2[] = "aaabcabcd";
// 	char	needle2[] = "cd";
// 	char	*ret2;

// 	ret = ft_strnstr(haystack, needle, 8);
// 	if (ret == NULL)
// 		printf("Needle(ft) was not found!\n");
// 	else
// 		printf("Needle(ft) was found! Return is '%s'!\n", ret);
// 	ret2 = strnstr(haystack2, needle2, 8);
// 	if (ret2 == NULL)
// 		printf("Needle(or) was not found!\n");
// 	else
// 		printf("Needle(or) was found! Return is '%s'!\n", ret2);
// 	return (0);
// }