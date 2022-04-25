/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:39 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/25 10:50:07 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_i(int *i, int *sign, const char *str, int *error)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		++*i;
	if (str[*i] == '-' || str[*i] == '+')
	{
		*sign = 1 - 2 * (str[*i] == '-');
		++*i;
	}
	if (!str[*i] || *sign < 0)
		*error = -1;
}

int	ft_atoi(const char *str, int *error)
{
	int		i;
	int		j;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	check_i(&i, &sign, str, error);
	j = i;
	while (str[j])
	{
		if (str[j] < 48 || str[j] > 57)
			*error = -1;
		++j;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + str[i] - '0';
		++i;
		if ((n > INT_MAX && sign > 0) || (n > (long)INT_MAX + 1 && sign < 0))
			*error = -1;
	}
	return (sign * n);
}

void	error_msg(int nbr)
{
	if (nbr < 0)
	{
		printf("ERROR!\n");
		printf("Input should be in the following form:\n");
		printf("./philo <n_of_philos> <time_to_die> <time_to_eat> ");
		printf("<time_to_sleep> [n_of_times_each_philo_should_eat]\n");
	}
}

void	ft_usleep(long ms)
{
	t_timeval	start;
	t_timeval	now;
	long		time;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	time = (now.tv_sec - start.tv_sec) * 1000
		+ (now.tv_usec - start.tv_usec) / 1000;
	while (time < ms)
	{
		usleep(900);
		gettimeofday(&now, NULL);
		time = (now.tv_sec - start.tv_sec) * 1000
			+ (now.tv_usec - start.tv_usec) / 1000;
	}
}

void	ft_print(t_philo *t_p, int par)
{
	pthread_mutex_lock(&t_p->print);
	if (par == 1)
		printf("%ld %d has taken a fork\n", check_time(t_p), t_p->p_i);
	else if (par == 2)
	{
		++t_p->each;
		printf("%ld %d is eating\n", check_time(t_p), t_p->p_i);
	}
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
