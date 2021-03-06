/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:30:29 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:30:30 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	ret;

// 	ret = ft_isprint('a');
// 	printf("return is %d\n", ret);
// 	ret = ft_isprint('\0');
// 	printf("return is %d\n", ret);
// 	ret = ft_isprint(' ');
// 	printf("return is %d\n", ret);
// 	ret = ft_isprint('~');
// 	printf("return is %d\n", ret);
// 	return (0);
// }