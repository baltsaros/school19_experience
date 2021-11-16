#include <unistd.h>
#include "doop.h"

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	*operator;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		if (ft_check_operator(argv[2]))
		{
			operator = argv[2];
			ft_operation(a, b, operator);
		}
		else
			write(1, "0\n", 2);
	}
	return (0);
}
