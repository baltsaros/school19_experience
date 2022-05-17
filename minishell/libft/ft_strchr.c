/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:33:16 by abuzdin           #+#    #+#             */
/*   Updated: 2022/05/17 12:36:00 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(char *s, int c)
{
	unsigned char	*str;
	unsigned char	x;
	size_t			i;

	if (!s)
		return (0);
	str = (unsigned char *)s;
	x = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == x)
			return (1);
		++i;
	}
	if (str[i] == x)
		return (1);
	return (0);
}
