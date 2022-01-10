/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:29:27 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:29:49 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str_ch;

	str_ch = (char *)s;
	while (n > 0 && *str_ch)
	{
		*str_ch = '\0';
		++str_ch;
		--n;
	}
}

// int	main(void)
// {
// 	char	str[] = "hello world";

// 	ft_bzero(str+4, 5);
// 	printf("new str is %s\n", str);
// 	return (0);
// }