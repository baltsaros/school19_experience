#include "philo.h"

void	set_params(t_input *t_in, t_philo *t_p)
{
	t_p->n = t_in->n;
	t_p->die = t_in->die;
	t_p->eat = t_in->eat;
	t_p->sleep = t_in->sleep;
	t_p->each = 0;
	t_p->dead = t_in->dead;
	t_p->t_st = t_in->t_st;
	gettimeofday(&t_p->t_meal, NULL);
	t_p->t_st = t_in->t_st;
}

int	philo_init(t_input *t_in)
{
	int	i;

	t_in->t_p = malloc(sizeof(t_philo) * t_in->n);
	t_in->fm = malloc(sizeof(mutex_t) * t_in->n);
	if (!t_in->t_p || !t_in->fm)
		return (-1);
	gettimeofday(&t_in->t_st, NULL);
	t_in->dead = 0;
	i = 0;
	while (i < t_in->n)
	{
		set_params(t_in, &t_in->t_p[i]);
		pthread_mutex_init(&t_in->fm[i], NULL);
		pthread_mutex_init(&t_in->t_p[i].print, NULL);
		if (t_in->n > 1)
			t_in->t_p[i].right = &t_in->fm[(t_in->n + i + 1) % t_in->n];
		else
			t_in->t_p[i].right = &t_in->fm[i];
		t_in->t_p[i].left = &t_in->fm[i];
		t_in->t_p[i].p_i = i + 1;
		++i;
	}
	pthread_mutex_init(&t_in->mutex, NULL);
	return (0);
}
