/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:28:57 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/18 15:37:54 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_control(int sign)
{
	if (sign < 0)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		n;
	int		digs;

	digs = 0;
	i = 0;
	sign = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i] == '-');
		++i;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + str[i] - '0';
		++i;
		++digs;
		if (digs > 19)
			return (ft_size_control(sign));
	}
	return (sign * n);
}
