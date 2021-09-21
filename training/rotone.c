#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	rotone_main(int argc, char **argv)
{
	int		i;
	int		j;

	j = 0;

	if (argc < 1)
	{
		ft_putchar('\n');
		return (0);
	}
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if ((argv[j][i] >= 'a' && 'z' >= argv[j][i])
			|| (argv[j][i] >= 'A' && argv[j][i] <= 'Z'))
				{
					argv[j][i] += 1;
					if (argv[j][i] == '{' || argv[j][i] == '[')
						argv[j][i] -= 25;
					ft_putchar(argv[j][i]);
				}
			++i;
		}
		ft_putchar('\n');
		++j;
	}
	return (0);
}

int	main(void)
{
	char	*argv[3];

	argv[0] = "hello";
	argv[1] = "you";
	argv[2] = "there";
	rotone_main(3, argv);
}