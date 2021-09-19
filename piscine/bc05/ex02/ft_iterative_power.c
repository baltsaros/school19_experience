/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 09:26:28 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/19 09:26:29 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
	{
		while (power != 1)
		{
			nb = nb * n;
			--power;
		}
		return (nb);
	}
}

/*
#include <stdio.h>
int		main()
{
	printf("%d\n", ft_iterative_power(3, -2));
	printf("%d\n", ft_iterative_power(3, 0));
	printf("%d\n", ft_iterative_power(3, 1));
	printf("%d\n", ft_iterative_power(3, 2));
	printf("%d\n", ft_iterative_power(3, 3));
	printf("%d\n", ft_iterative_power(3, 4));
	printf("%d\n", ft_iterative_power(3, 5));
	return (0);
}
*/