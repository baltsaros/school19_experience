#include <stdio.h>

int	ft_any(char **tab, int (*f)(char *))
{
	int		i;

	i = 0;
	while (tab[i] != 0)
	{
		if ((*f)(tab[i]) > 0)
			return (1);
		++i;
	}
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 96 || str[i] > 122)
			return (0);
		++i;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	// argv[0] = "one";
	// argv[1] = "two";
	// argv[2] = "three";
	// argv[3] = "Tfour";
	// argv[4] = 0;
	// (void)argc;
	if (argc > 1)
		printf("return is %d\n", ft_any(argv, &ft_str_is_lowercase));
	return (0);
}
