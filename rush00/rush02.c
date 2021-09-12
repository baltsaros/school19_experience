#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_fullline(int x)
{
	int		i = 1;

		ft_putchar('A');
		while (++i != x)
		{
			ft_putchar('B');
		}
		ft_putchar('A');
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

void	ft_lastline(int x)
{
	int		i = 1;

		ft_putchar('C');
		while (++i != x)
		{
			ft_putchar('B');
		}
		ft_putchar('C');
		ft_putchar('\n');	
}

void	ft_firstcolumn(int y)
{
	int		i = 1;

		ft_putchar('A');
		ft_putchar('\n');
		while (++i != y)
		{
			ft_putchar('B');
			ft_putchar('\n');
		}
		ft_putchar('C');
		ft_putchar('\n');
}
void	rush(int x, int y)
{
	if (x == 1 && y == 1)
	{
		ft_putchar('A');
		ft_putchar('\n');
	}
	else if ( x > 1 && y == 1)
	{
		ft_fullline(x);
	}

	else if ( x == 1 && y > 1)
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
		ft_lastline(x);
	}
}

int		main()
{
	rush(4, 4);
	return (0);
}
