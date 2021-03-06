#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	box[256];

	i = 0;
	while (i < 255)
	{
		box[i] = 0;
		++i;
	}
	i = 0;
	while (s1[i])
	{
		if (!(box[(unsigned int)s1[i]]))
		{
			box[(unsigned int)s1[i]] = 1;
			ft_putchar((unsigned int)s1[i]);
		}	
		++i;
	}
	i = 0;
	while (s2[i])
	{
		if (!(box[(unsigned int)s2[i]]))
		{
			box[(unsigned int)s2[i]] = 1;
			ft_putchar((unsigned int)s2[i]);
		}	
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		ft_putchar('\n');
	else
		ft_union(argv[1], argv[2]);
	return (0);
}