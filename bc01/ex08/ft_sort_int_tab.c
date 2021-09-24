#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		tmp;
	int		i;
	int		j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] > tab[j])
				{
					tmp = tab[j];
					tab[j] = tab[i];
					tab[i] = tmp;
				}
			++i;
		}
		++j;
	}
}

int	main(void)
{
	int		tab[1] = {};
	int		j = 0;

	tab[0] = 5;

	ft_rev_int_tab(tab, 7);
	while (j != 7)
	{
		printf("%d ", tab[j]);
		++j;
	}
	return (0);
}
