/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 09:27:16 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/19 09:27:17 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_recursive_power(int nb, int power)
{
	int	n;

	if (power > 0)
	{
		--power;
		n = nb * ft_recursive_power(nb, power);
		return (n);
	}
	if (power == 0)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_recursive_power(3, -2));
	printf("%d\n", ft_recursive_power(3, 0));
	printf("%d\n", ft_recursive_power(3, 1));
	printf("%d\n", ft_recursive_power(3, 2));
	printf("%d\n", ft_recursive_power(3, 3));
	printf("%d\n", ft_recursive_power(3, 4));
	printf("%d\n", ft_recursive_power(3, 5));
	printf("%d\n", ft_recursive_power(46340, 2));
	return (0);
}
*/