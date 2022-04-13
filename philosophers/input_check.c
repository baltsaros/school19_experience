#include "philo.h"

t_input	input_check(t_input t_in, int argc, char *argv[])
{
	
	t_in.error = 0;
	if (argc != 5 && argc != 6)
	{
		t_in.error = -1;
		return (t_in);
	}
	t_in.n = ft_atoi(argv[1], &t_in.error);
	t_in.die = ft_atoi(argv[2], &t_in.error);
	t_in.eat = ft_atoi(argv[3], &t_in.error);
	t_in.sleep = ft_atoi(argv[4], &t_in.error);
	if (t_in.n == 0)
		t_in.error = -1;
	if (argv[5])
		t_in.each = ft_atoi(argv[5], &t_in.error);
	else
		t_in.each = 0;
	return (t_in);
}
