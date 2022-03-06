#include "push_swap.h"

void	error_msg()
{
	write(1, "Error\n", 6);
	exit(1);
}


void	input_check(int argc, char *argv[])
{
	size_t	i;
	size_t	j;
	char	**input;
	int		*ar;

	ar = malloc(sizeof(int) * (argc - 1));
	alloc_check_small(ar);
	i = 1;
	j = 0;
	while (argv[i])
	{
		ar[j] = ft_atoi(argv[i]);
		printf("ar[%zu] is %d, argv[%zu] is %s\n", j, ar[j], i, argv[i]);
		++i;
		++j;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	input_check(argc, argv);
	return (0);
}
