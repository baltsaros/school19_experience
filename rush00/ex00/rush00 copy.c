/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:15:37 by cbukuba           #+#    #+#             */
/*   Updated: 2021/09/12 17:16:58 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	f_line(int x, int y)
{
	int	cmp;

	ft_putchar('o');
	cmp = 0;
	while (cmp < (x - 2))
	{
		ft_putchar('-');
		cmp ++;
	}
	if (x > 1)
	{
		ft_putchar('o');
	}
}

void	m_line(int x, int y)
{
	int	cmp;
	int	i;

	cmp = 0;
	while (cmp < (y - 2))
	{
		ft_putchar('\n');
		ft_putchar('|');
		i = 0;
		while (i < (x - 2))
		{
			ft_putchar(' ');
			i ++;
		}
		if (x > 1)
		{
			ft_putchar('|');
		}
		cmp ++;
	}	
}

void	rush(int x, int y)
{
	if (x > 1 && y > 1)
	{
		f_line(x, y);
		m_line(x, y);
		ft_putchar('\n');
		f_line(x, y);
	}
	if (x > 1 && y == 1)
	{
		f_line(x, y);
	}
	if (x == 1 && y == 1)
	{
		ft_putchar('o');
	}
	if (x == 1 && y > 1)
	{
		f_line(x, y);
		m_line(x, y);
		ft_putchar('\n');
		f_line(x, y);
	}
}
