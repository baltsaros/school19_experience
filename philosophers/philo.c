#include "philo.h"



int	main(int argc, char *argv[])
{
	t_input	in;
	struct timeval	time;

	in.error = 0;
	in = input_check(in, argc, argv);
	if (in.error)
	{
		error_msg(in.error);
		return (-1);
	}
	gettimeofday(&time, NULL);
	printf("seconds: %ld, microseconds %d\n", time.tv_sec + time.tv_usec, time.tv_usec);
	return (0);
}

	// printf("n %d, f %d, die %d, eat %d, sleep %d, each %d\n", in.n, in.f, in.die, in.eat, in.sleep, in.each);