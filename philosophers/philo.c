#include "philo.h"

void	philo_init(t_input *t_in)
{
	int	i;

	i = 0;
	while (i < t_in->n)
	{
		t_in->t_p[i].right = &t_in->fm[i + t_in->n * (i == 0)];
		t_in->t_p[i].left = &t_in->fm[i + 1];
		t_in->t_p[i].p_i = i + 1;
		t_in->t_p[i].p_thread = malloc(sizeof(pthread_t));
		if (!t_in->t_p[i].p_thread)
			return (-1);
		++i;
	}
}

void	philo(void *args)
{
	while(1)
	{
		pthread_mutex_lock(&args)
	}
}

int	main(int argc, char *argv[])
{
	t_input			t_in;
	struct timeval	start;
	int				i;

	t_in.error = 0;
	t_in = input_check(t_in, argc, argv);
	if (t_in.error)
	{
		error_msg(t_in.error);
		return (-1);
	}
	t_in.t_p = malloc(sizeof(t_philo) * t_in.n);
	t_in.fm = malloc(sizeof(mutex_t) * t_in.n);
	if (!t_in.t_p || !t_in.fm)
		return (-1);
	i = 0;
	gettimeofday(&start, NULL);
	while (i < t_in.n)
	{
		pthread_mutex_init(&t_in.fm[i], NULL);
		++i;
	}
	i = 0;
	while (i < t_in.n)
	{
		pthread_create(&t_in.p[i], NULL, philo, (void *)&t_in);
		++i;
	}
	while (i > 0)
	{
		--i;
		pthread_detach(t_in.p[i]);
	}
	free(t_in.p);
	free(t_in.fm);
	return (0);
}

	// printf("n %d, f %d, die %d, eat %d, sleep %d, each %d\n", 
		// in.n, in.f, in.die, in.eat, in.sleep, in.each);
	// printf("seconds: %ld, microseconds %d\n", time.tv_sec + time.tv_usec, time.tv_usec);