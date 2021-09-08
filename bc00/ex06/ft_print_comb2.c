/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:45:31 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/08 11:45:44 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a == '9' && b == '8')
	{
		write(1, "", 0);
	}
	else
	{
		write(1, ", ", 2);
	}
}

void	ft_put_comb2(void)
{
	char	a;
	char	b;

	a = 0;
	b = 0;
	while (b++ <= 98)
	{
		ft_putchar(a / 10 + 48, a % 10 + 48, b / 10 + 48, b % 10 + 48);
		if (b == 99)
		{
			a++;
			b = a;
		}
	}
}

int		main()
{
	ft_put_comb2();
	return 0;
}
