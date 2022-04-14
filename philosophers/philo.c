#include "philo.h"
void	set_params(t_input *t_in, t_philo *t_p)
{
	t_p->n = t_in->n;
	t_p->die = t_in->die;
	t_p->eat = t_in->eat;
	t_p->sleep = t_in->sleep;
	t_p->each = t_in->each;
	t_p->dead = t_in->dead;
	gettimeofday(&t_p->t_meal, NULL);
}

int	philo_init(t_input *t_in)
{
	int	i;

	t_in->dead = 0;
	i = 0;
	while (i < t_in->n)
	{
		set_params(t_in, &t_in->t_p[i]);
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

int	check_death(void *args)
{
	t_philo		*t_p;
	t_timeval	t_check;

	t_p = (t_philo *) args;
	gettimeofday(&t_check, NULL);
	if (((t_check.tv_sec - t_p->t_meal.tv_sec) * 1000 + (t_check.tv_usec 
		- t_p->t_meal.tv_usec) / 1000) >= t_p->die)
		return (-1);
	return (0);
}


void	philo(void *args)
{
	t_philo	*t_p;

	t_p = (t_philo *) args;
	if ((t_p->p_i % 2) == 0)
		usleep(20);
	while(1)
	{
		pthread_mutex_lock(t_p->left);
		printf("%d has taken a fork\n", t_p->p_i);
		pthread_mutex_lock(t_p->right);
		printf("%d has taken a fork\n", t_p->p_i);
		printf("%d is eating\n", t_p->p_i);
		gettimeofday(&t_p->t_meal, NULL);
		usleep(t_p->eat * 1000);
		pthread_mutex_unlock(t_p->left);
		pthread_mutex_unlock(t_p->right);
		printf("%d is sleeping\n", t_p->p_i);
		usleep(t_p->sleep * 1000);
		printf("%d is thinking\n", t_p->p_i);
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
	ret = philo_init(&t_in);
	if (!ret)
		return (-1);
	i = 0;
	while (i < t_in.n)
	{
		pthread_create(&t_in.t_p[i].p_thread, NULL, philo, (void *)&t_in.t_p[i]);
		++i;
	}
	i = 0;
	while (1)
	{
		i = (t_in.n + i) % t_in.n;
		if (check_death(&t_in.t_p[i]) < 0)
		{
			printf("%d died\n", t_in.t_p[i].p_i);
			free_all(t_in);
			return (0);
		}
		++i;
	}
	free_all(t_in);
	return (0);
}

	// printf("n %d, f %d, die %d, eat %d, sleep %d, each %d\n", 
		// in.n, in.f, in.die, in.eat, in.sleep, in.each);
	// printf("seconds: %ld, microseconds %d\n", time.tv_sec + time.tv_usec, time.tv_usec);
		// printf("philo[%d]: left - %d, right - %d\n", i + 1, i + 1, i + t_in->n * (i == 0));
	// printf("n %d, die %d, eat %d, sleep %d, each %d, dead %d\n"
	// 	, t_in->n, t_in->die, t_in->eat, t_in->sleep, t_in->each, t_in->dead);