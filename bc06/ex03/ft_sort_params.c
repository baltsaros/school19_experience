#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			++i;
	}
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	j = argc - 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], argv[j]) > 0)
		{
			tmp = argv[j];
			argv[j] = argv[i];
			argv[i] = tmp;
		}
		++i;
		--j;
	}
	j = 1;
	while (j < argc)
	{
		ft_putstr(argv[j]);
		++j;
	}
	return (0);
}
