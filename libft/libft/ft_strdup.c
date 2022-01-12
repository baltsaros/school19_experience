/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:33:21 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/12 14:13:58 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	if (!s)
		size = -1;
	while (s[size])
		++size;
	dest = (char *)malloc(sizeof(*s) * (size + 1));
	if (NULL == dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

// int		main()
// {
// 	// char	src[] = "Copy me";
// 	// char	src2[] = "Copy me";

// 	printf("dest(ft) is %s\n", ft_strdup((void *)0));
// 	// printf("dest(or) is %s\n", strdup((void *)0));
// 	return (0);
// }