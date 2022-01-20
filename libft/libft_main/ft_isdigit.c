/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:30:25 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:30:26 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	ret;

// 	ret = ft_isdigit('a');
// 	printf("return is %d\n", ret);
// 	ret = ft_isdigit('0');
// 	printf("return is %d\n", ret);
// 	ret = ft_isdigit('9');
// 	printf("return is %d\n", ret);
// 	ret = ft_isdigit('.');
// 	printf("return is %d\n", ret);
// 	return (0);
// }