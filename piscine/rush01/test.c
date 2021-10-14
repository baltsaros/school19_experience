int	check_rows(int argc, char *argv[], int *tab[])
{
	int		c; // column
	int		k; // argv index

	c = 0;
	k = 1;

	while (k < 5)  // check for headers, if there are 1 and 4, place boxes 4 and 1
	{
		if (argv[k] == 1)
		{
			tab[0][c] = 4;
			if (argv[k] == 4)
				tab[0][c] = 1;
		}
		++k;
		++c;
	}
	c = 0;
	while (k < 9)
	{
		if (argv[k] == 1)
		{
			tab[3][c] = 4;
			if (argv[k] == 4)
				tab[3][c] = 1;
		}
		++k;
		++c;
	}
	return (tab);
}

int	main (int argc, char **argv)
{
	int		r;
	int		c;
	int		k;
	int		*tab[];

	tab[0] = {0, 0, 0, 0};
	tab[1] = {0, 0, 0, 0};
	tab[2] = {0, 0, 0, 0};
	tab[3] = {0, 0, 0, 0};


}