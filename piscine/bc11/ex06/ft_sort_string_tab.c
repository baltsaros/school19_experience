#include <stdio.h>

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while(s1[i] && s2[i] && (s1[i] == s2[i]))
		++i;
	return(s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			++i;
	}
}

int		main(void)
{
	char	*tab[7];
	int		i;

	tab[0] = "za";
	tab[1] = "na";
	tab[2] = "ea";
	tab[3] = "ca";
	tab[4] = "ba";
	tab[5] = "aa";
	tab[6] = 0;
	i = 0;
	while (tab[i])
	{
		printf("tab[%d] is '%s'\n", i, tab[i]);
		++i;
	}
	printf("----------------\n");
	ft_sort_string_tab(tab);
	i = 0;
	while (tab[i])
	{
		printf("tab[%d] is '%s'\n", i, tab[i]);
		++i;
	}
	return (0);
}
