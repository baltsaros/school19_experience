/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 07:55:36 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/10 07:55:38 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>
int		main()
{
	int		div;
	int		mod;

	ft_div_mod(44, 5, &div, &mod);
	printf("%d\n", div);
	printf("%d\n", mod);
	return 0;
}
*/
