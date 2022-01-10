/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:34:26 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:34:27 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

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
// 	char	s[] = "Hello world!";
// 	char	*ret;

// 	ret = ft_substr(s, 2, 4);
// 	if (NULL == ret)
// 		printf("Ret is null!\n");
// 	else
// 		printf("Ret is '%s' Size of ret is %ld.\n", ret, sizeof(ret));
// 	free(ret);
// 	return (0);
// }