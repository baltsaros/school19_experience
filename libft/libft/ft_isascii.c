/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:30:20 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/11 13:45:57 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	unsigned int	i;
	
	i = (unsigned int)c;
	if (i >= 0 && i <= 127)
		return (1);
	else
		return (0);
}

int	main(void)
{
	int	ret;

	ret = ft_isascii('ç');
	printf("for 'ç' return is %d\n", ret);
	return (0);
}