/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 09:27:47 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/19 09:27:50 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_fibonacci(int index)
{
	int	n;

	if (index > 1)
	{
		--index;
		n = ft_fibonacci(index) + ft_fibonacci(index - 1);
		return (n);
	}
	if (index == 1)
		return (1);
	if (index == 0)
		return (0);
	else
		return (-1);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_fibonacci(-2));
	printf("%d\n", ft_fibonacci(0));
	printf("%d\n", ft_fibonacci(1));
	printf("%d\n", ft_fibonacci(2));
	printf("%d\n", ft_fibonacci(3));
	printf("%d\n", ft_fibonacci(4));
	printf("%d\n", ft_fibonacci(5));
	printf("%d\n", ft_fibonacci(10));
}
*/