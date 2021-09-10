void	ft_rev_int_tab(int *tab, int size)
{
	int		tab2[size];
	int		i;

	i = 0;
	while (size >= 0)
	{
		tab2[i] = tab[size - 1];
		i++;
		size--;
	}
}



int		main()
{
	int	tab[] = { 1, 2, 3, 4};

	ft_rev_int_tab(tab, 5);

}
