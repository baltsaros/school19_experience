#include "philo.h"

int	free_all(t_input *t_in)
{
	int	i;

	i = 0;
	while (i < t_in->n)
	{
		pthread_detach(t_in->t_p->p_thread);
		pthread_mutex_destroy(&t_in->t_p[i].print);
		pthread_mutex_destroy(&t_in->fm[i]);
		++i;
	}
	pthread_mutex_destroy(&t_in->mutex);
	free(t_in->t_p);
	free(t_in->fm);
	return (0);
}
