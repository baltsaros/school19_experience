/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:42:52 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/10 15:42:55 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *a, int *b)
{
	int		c;

	c = *b;
	*b = *a;
	*a = c;
}

/*
#include <stdio.h>
int main()
{
	int		a;
	int		b;

	a = 42;
	b = 19;

	printf("%d\n", a);
	printf("%d\n", b);
	ft_swap(&a, &b);
	printf("%d\n", a);
	printf("%d\n", b);
	return 0;
}
*/
