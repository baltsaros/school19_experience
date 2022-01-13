/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:34:26 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/13 15:45:01 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_s;
	size_t	len_new;

	if (!s)
		return ((char *)s);
	len_s = ft_strlen(s);
	len_new = 0;
	while (s[start + len_new] && len >= len_new)
		++len_new;
	substr = (char *)malloc(sizeof(*substr) * (len_new + 1));
	if (NULL == substr)
		return (0);
	if (len_s < start)
	{
		ft_memset(substr, 0, len_new + 1);
		return (substr);
	}
	ft_strlcpy(substr, s + start, len_new + 1);
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
int	main(void)
{
	char	s[] = "Hello world!";
	char	*ret;

	ret = ft_substr(s, 1, 1);
	if (NULL == ret)
		printf("Ret is null!\n");
	else
		printf("Ret is '%s'\n", ret);
	free(ret);
	return (0);
}