#include "philo.h"

void	philo(void *args)
{

}

int	main(int argc, char *argv[])
{
	t_input			in;
	struct timeval	time;
	int				i;

	in.error = 0;
	in = input_check(in, argc, argv);
	if (in.error)
	{
		error_msg(in.error);
		return (-1);
	}
	in.p = malloc(sizeof(pthread_t) * in.n);
	in.fm = malloc(sizeof(mutex_t) * in.f);
	if (!in.p || !in.f)
		return (-1);
	i = 0;
	while (i < in.n)
	{
		pthread_mutex_init(&in.fm[i], NULL);
		++i;
	}
	pthread_create(&in.p[i], NULL, philo, (void *)&in);
	while (i > 0)
	{
		--i;
		pthread_detach(in.p[i]);
	}
	free(in.p);
	free(in.fm);
	return (0);
}

	// printf("n %d, f %d, die %d, eat %d, sleep %d, each %d\n", 
		// in.n, in.f, in.die, in.eat, in.sleep, in.each);
	// printf("seconds: %ld, microseconds %d\n", time.tv_sec + time.tv_usec, time.tv_usec);