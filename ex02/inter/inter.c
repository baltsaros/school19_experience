#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_inter(char *s1, char *s2)
{
	int	i;
	int	j;
	int	box[255];

	i = 0;
	while (i < 255)
	{
		box[i] = 0;
		++i;
	}
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j] != s1[i])
			++j;
		if (s1[i] == s2[j] && !box[s1[i]])
		{
			ft_putchar(s1[i]);
			box[s1[i]] = 1;
		}
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	else
		ft_inter(argv[1], argv[2]);
	return (0);
}
