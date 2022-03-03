#include "push_swap.h"

void	error_msg()
{
	write(1, "Error\n", 6);
	exit(1);
}

// void	input_check(int argc, char *argv[])
// {
// 	size_t	i;
// 	char	**input;
// 	int		*ar;

// 	ar = malloc(sizeof(int) * (argc - 1));
// 	alloc_check_small(ar);
// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (!ft_isdigit(argv[i]))
// 			error_msg();
// 		++i;
// 	}
// }

// int	main(int argc, char *argv[])
// {
// 	if (argc == 1)
// 		return (0);
// 	input_check(argc, argv);
// 	return (0);
// }
