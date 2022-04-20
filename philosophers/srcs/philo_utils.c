/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:39 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/20 10:33:42 by abuzdin          ###   ########.fr       */
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
		usleep(10);
		gettimeofday(&now, NULL);
		time = (now.tv_sec - start.tv_sec) * 1000
			+ (now.tv_usec - start.tv_usec) / 1000;
	}
}

int	error_check(int nbr)
{
	if (nbr < 0)
	{
		printf("Error!\n");
		return (-1);
	}
	return (0);
}
