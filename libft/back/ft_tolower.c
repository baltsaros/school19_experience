/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:34:31 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:34:32 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}

// int	main(void)
// {
// 	int		c;

// 	c = 'a';
// 	printf("c was '%c' and now is '%c'\n", c, ft_tolower(c));
// 	c = 'A';
// 	printf("c was '%c' and now is '%c'\n", c, ft_tolower(c));
// 	c = '1';
// 	printf("c was '%c' and now is '%c'\n", c, ft_tolower(c));
// 	c = '~';
// 	printf("c was '%c' and now is '%c'\n", c, ft_tolower(c));
// 	c = 'z';
// 	printf("c was '%c' and now is '%c'\n", c, ft_tolower(c));
// 	c = 'Z';
// 	printf("c was '%c' and now is '%c'\n", c, ft_tolower(c));
// 	return (0);
// }