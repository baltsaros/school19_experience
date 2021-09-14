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

void	ft_putcharcomma(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	write(1, ", ", 2);
}

void	ft_putcharspace(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0' - 1;
	while (a++ < '7')
	{
		b = a;
		while (b++ < '8')
		{
			c = b;
			while (c++ < '9')
			{
				if (a != '7')
				{
					ft_putcharcomma(a, b, c);
				}
				else
				{
					ft_putcharspace(a, b, c);
				}
			}
		}
	}
}

int     main()
{
    ft_print_comb();
    return 0;
}
