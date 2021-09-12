/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 13:37:36 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/12 13:37:38 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_fullline(int x)
{
	int		i;

	i = 0;
	ft_putchar('A');
	while (++i != x)
	{
		ft_putchar('B');
	}
	ft_putchar('C');
	ft_putchar('\n');
}

void	ft_halfline(int x)
{
	int		i;

	ft_putchar('B');
	i = 1;
	while (x > ++i)
	{
		ft_putchar(' ');
	}
	ft_putchar('B');
	ft_putchar('\n');
}

void	ft_firstcolumn(int y)
{
	int		i;

	i = 0;
	ft_putchar('A');
	ft_putchar('\n');
	while (++i != y)
	{
		ft_putchar('B');
		ft_putchar('\n');
	}
	ft_putchar('A');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x == 1 && y == 1)
	{
		ft_putchar('A');
		ft_putchar('\n');
	}
	else if (x > 1 && y == 1)
	{
		ft_fullline(x);
	}
	else if (x == 1 && y > 1)
	{
		ft_firstcolumn(y);
	}
	else
	{
		ft_fullline(x);
		while (--y > 1)
		{
			ft_halfline(x);
		}
		ft_fullline(x);
	}
}
