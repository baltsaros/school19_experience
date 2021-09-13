/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 07:56:22 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/10 07:56:26 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int		div;
	int		mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}


#include <stdio.h>
int main()
{
	int		a;
	int		b;

	a = 44;
	b = 5;
	printf("a(initial) %d, b(initial) %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a(div) %d, b(mod) %d\n", a, b);
	return 0;
}
