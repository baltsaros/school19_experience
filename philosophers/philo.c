#include "philo.h"

int	philo_init(t_input *t_in)
{
	int	i;

	t_in->dead = 0;
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
	return (0);
}

void	philo(void *args)
{
	if (args->t_p)
	while(1)
	{
		pthread_mutex_lock(&args);
	}
}

int	main(int argc, char *argv[])
{
	t_input		t_in;
	int			i;
	int			ret;

	t_in = input_check(t_in, argc, argv);
	if (t_in.error < 0)
	{
		error_msg(t_in.error);
		return (-1);
	}
	ret = 0;
	t_in.t_p = malloc(sizeof(t_philo) * t_in.n);
	t_in.fm = malloc(sizeof(mutex_t) * t_in.n);
	if (!t_in.t_p || !t_in.fm)
		return (-1);
	i = 0;
	while (i < t_in.n)
	{
		pthread_mutex_init(&t_in.fm[i], NULL);
		++i;
	}
	gettimeofday(&t_in.t_start, NULL);
	ret = philo_init(&t_in);
	if (!ret)
		return (-1);
	i = 0;
	while (i < t_in.n)
	{
		pthread_create(&t_in.t_p[i].p_thread, NULL, philo, &t_in);
		++i;
	}
	free_all(t_in);
	return (0);
}

	// printf("n %d, f %d, die %d, eat %d, sleep %d, each %d\n", 
		// in.n, in.f, in.die, in.eat, in.sleep, in.each);
	// printf("seconds: %ld, microseconds %d\n", time.tv_sec + time.tv_usec, time.tv_usec);
		// printf("philo[%d]: left - %d, right - %d\n", i + 1, i + 1, i + t_in->n * (i == 0));