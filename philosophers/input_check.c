#include "philo.h"

t_input	input_check(t_input in, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		in.error = 1;
		return (in);
	}
	in.n = ft_atoi(argv[1], &in.error);
	in.f = in.n;
	in.die = ft_atoi(argv[2], &in.error);
	in.eat = ft_atoi(argv[3], &in.error);
	in.sleep = ft_atoi(argv[4], &in.error);
	if (argv[5])
		in.each = ft_atoi(argv[5], &in.error);
	else
		in.each = 0;
	return (in);
}
