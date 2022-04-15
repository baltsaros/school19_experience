#include "philo.h"
void	set_params(t_input *t_in, t_philo *t_p)
{
	t_p->n = t_in->n;
	t_p->die = t_in->die;
	t_p->eat = t_in->eat;
	t_p->sleep = t_in->sleep;
	t_p->each = t_in->each;
	t_p->dead = t_in->dead;
	t_p->t_st = t_in->t_st;
	gettimeofday(&t_p->t_meal, NULL);
	t_p->t_st = t_in->t_st;
}

int	philo_init(t_input *t_in)
{
	int	i;

	t_in->dead = 0;
	i = 0;
	while (i < t_in->n)
	{
		set_params(t_in, &t_in->t_p[i]);
		if (t_in->n > 1)
			t_in->t_p[i].left = &t_in->fm[(t_in->n + i + 1) % t_in->n];
		else
			t_in->t_p[i].left = NULL;
		t_in->t_p[i].right = &t_in->fm[i];
		t_in->t_p[i].p_i = i + 1;
		++i;
	}
	return (0);
}

long	check_time(t_philo *t_p)
{
	long	time;

	time = 0;
	gettimeofday(&t_p->t_act, NULL);
	time  = (t_p->t_act.tv_sec - t_p->t_st.tv_sec) * 1000
		+ (t_p->t_act.tv_usec - t_p->t_st.tv_usec) / 1000;
	return (time);
}

int	check_death(void *args)
{
	t_philo		*t_p;
	t_timeval	t_check;
	long		time;

	// printf("check death\n");
	t_p = (t_philo *) args;
	gettimeofday(&t_check, NULL);
	time  = (t_check.tv_sec - t_p->t_meal.tv_sec) * 1000 + (t_check.tv_usec 
		- t_p->t_meal.tv_usec) / 1000;
	// printf("time %ld - die %ld\n", time, t_p->die);
	if (time >= t_p->die)
		return (-1);
	return (0);
}


void	*philo(void *args)
{
	t_philo	*t_p;

	t_p = (t_philo *) args;
	if ((t_p->p_i % 2) == 0)
		usleep(1000);
	while(1)
	{
		pthread_mutex_lock(t_p->right);
		printf("%ld %d has taken a fork\n", check_time(t_p), t_p->p_i);
		pthread_mutex_lock(t_p->left);
		printf("%ld %d has taken a fork\n", check_time(t_p), t_p->p_i);
		printf("%ld %d is eating\n", check_time(t_p), t_p->p_i);
		gettimeofday(&t_p->t_meal, NULL);
		usleep(t_p->eat * 1000);
		pthread_mutex_unlock(t_p->right);
		pthread_mutex_unlock(t_p->left);
		printf("%ld %d is sleeping\n", check_time(t_p), t_p->p_i);
		usleep(t_p->sleep * 1000);
		printf("%ld %d is thinking\n", check_time(t_p), t_p->p_i);
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
	gettimeofday(&t_in.t_st, NULL);
	printf("philo init\n");
	ret = philo_init(&t_in);
	i = 0;
	printf("threading\n");
	while (i < t_in.n)
	{
		pthread_create(&t_in.t_p[i].p_thread, NULL, philo, (void *)&t_in.t_p[i]);
		++i;
	}
	i = 0;
	printf("death loop\n");
	while (1)
	{
		i = (t_in.n + i) % t_in.n;
		if (check_death(&t_in.t_p[i]) < 0)
		{
			printf("%ld %d died\n", check_time(&t_in.t_p[i]), t_in.t_p[i].p_i);
			free_all(t_in);
			return (0);
		}
		// printf("i is %d\n", i);
		++i;
	}
	printf("free and exit\n");
	free_all(t_in);
	return (0);
}

	// printf("n %d, f %d, die %d, eat %d, sleep %d, each %d\n", 
		// in.n, in.f, in.die, in.eat, in.sleep, in.each);
	// printf("seconds: %ld, microseconds %d\n", time.tv_sec + time.tv_usec, time.tv_usec);
		// printf("philo[%d]: left - %d, right - %d\n", i + 1, i + 1, i + t_in->n * (i == 0));
	// printf("n %d, die %d, eat %d, sleep %d, each %d, dead %d\n"
	// 	, t_in->n, t_in->die, t_in->eat, t_in->sleep, t_in->each, t_in->dead);