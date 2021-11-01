#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_array(int *array, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(array[i] + 48);
		++i;
	}
	if (array[0] != 10 - n)
		write(1, ", ", 2);
}

void	make_combo(int *array, int n)
{
	int		i;

	while (1)
	{
		i = 0;
		while (array[n - 1] < 9)
		{
			array[n - 1] += 1;
			print_array(array, n);
		}
		while (array[n - 1 - i] == 9 - i && i < n)
			++i;
		if (i == n)
			break;
		array[n - 1 - i] += 1;
		array[n - i] = array[n - 1 - i];
	}
}

void	ft_print_combn(int n)
{
	int		array[9];
	int		i;

	i = 0;
	while (i < n)
	{
		array[i] = i;
		ft_putchar(array[i] + 48);
		++i;
	}
	write(1, ", ", 2);
	make_combo(array, n);
}

int	main(void)
{
	ft_print_combn(2);
	write(1, "\n", 1);
	return (0);
}
