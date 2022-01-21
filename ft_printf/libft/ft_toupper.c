/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:34:37 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:34:38 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

// int	main(void)
// {
// 	int		ch;

// 	ch = 'a';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	ch = 'A';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	ch = '0';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	ch = '/';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	ch = 'z';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	ch = 'Z';
// 	printf("c was '%c' and now is '%c'\n", ch, ft_toupper(ch));
// 	return (0);
// }