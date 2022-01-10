/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:34:26 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 17:58:08 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!(char *)s)
		return (NULL);
	substr = (char *)malloc(sizeof(*substr) * (len + 1));
	if (NULL == substr)
		return (NULL);
	i = 0;
	while (len > i && s[start + i])
	{
		substr[i] = s[start + i];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}

// int	main(void)
// {
// 	char	str[] = "lorem ipsum dolor sit amet";
// 	char	*strsub;
// 	char	*test;

// 	if (!(strsub = ft_substr(str, 400, 20)))
// 		printf("NULL\n");
// 	else
// 	{
// 		test = (char *)&strsub[30];
// 		test = "TEST TEST";
// 		if (strsub)
// 			printf("Substr is %s\n", strsub);
// 		else
// 			printf("Fail\n");
// 	}
// 	if (str == strsub)
// 		printf("No return for substr");
// 	(void)test;
// 	return (0);
// }