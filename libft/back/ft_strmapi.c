/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:33:49 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:51:52 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	if (!(s))
		return (NULL);
	s2 = (char *)malloc(sizeof(s2) * (ft_strlen(s) + 1));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = (*f)(i, s[i]);
		++i;
	}
	s2[i] = '\0';
	return (s2);
}

// char	ft_to_uppercase(unsigned int i, char ch)
// {
// 	printf("s[%d] is %c\n", i, ch);
// 	if (ch >= 97 && ch <= 122)
// 		ch = ch - 32;
// 	return (ch);
// }

// int		main(void)
// {
// 	char	s[] = "Hello world!";
// 	char	*s_mapped;

// 	printf("Initial str is '%s'\n", s);
// 	s_mapped = ft_strmapi(s, &ft_to_uppercase);
// 	printf("Mapped str is '%s'\n", s_mapped);
// 	return (0);
// }