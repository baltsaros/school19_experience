#include "philo.h"

void	ft_states(void *args, int philo, int par)
{
	if (par == 1)
		printf("%d has taken a fork\n", philo);
	else if (par == 2)
		printf("%d is eating\n", philo);
	else if (par == 3)
		printf("%d is sleeping\n", philo);
	else if (par == 4)
		printf("%d is thinking\n", philo);
	else if (par == 5)
		printf("%d died\n", philo);
	else
		printf("Error! Invalid parameter!\n");
}