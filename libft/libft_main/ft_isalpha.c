/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:30:14 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:30:16 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	ret;

// 	ret = ft_isalpha('A');
// 	printf("return is %d\n", ret);
// 	ret = ft_isalpha('Z');
// 	printf("return is %d\n", ret);
// 	ret = ft_isalpha('a');
// 	printf("return is %d\n", ret);
// 	ret = ft_isalpha('z');
// 	printf("return is %d\n", ret);
// 	ret = ft_isalpha('1');
// 	printf("return is %d\n", ret);
// 	ret = ft_isalpha(' ');
// 	printf("return is %d\n", ret);
// 	return (0);
// }