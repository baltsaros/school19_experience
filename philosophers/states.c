#include "philo.h"

void	ft_print(t_philo *t_p, int par)
{
	pthread_mutex_lock(&t_p->print);
	if (par == 1)
		printf("%ld %d has taken a fork\n", check_time(t_p), t_p->p_i);
	else if (par == 2)
		printf("%ld %d is eating\n", check_time(t_p), t_p->p_i);
	else if (par == 3)
		printf("%ld %d is sleeping\n", check_time(t_p), t_p->p_i);
	else if (par == 4)
		printf("%ld %d is thinking\n", check_time(t_p), t_p->p_i);
	else if (par == 5)
		printf("%ld %d died\n", check_time(t_p), t_p->p_i);
	else
		printf("Error! Invalid parameter!\n");
	pthread_mutex_unlock(&t_p->print);
}