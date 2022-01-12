/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:34:26 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/12 14:45:54 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	len_s;

	if (!s)
		return ((char *)s);
	len_s = ft_strlen(s);
	substr = (char *)malloc(sizeof(*substr) * (len + 1));
	if (NULL == substr)
		return (0);
	if (len_s < start)
	{
		ft_memset(substr, 0, len + 1);
		return (substr);
	}
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
// int	main(void)
// {
// 	char	s[] = "Hello world!";
// 	char	*ret;

// 	ret = ft_substr(s, 2, 20);
// 	if (NULL == ret)
// 		printf("Ret is null!\n");
// 	else
// 		printf("Ret is '%s' Size of ret is %ld.\n", ret, sizeof(ret));
// 	free(ret);
// 	return (0);
// }