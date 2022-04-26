/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:39 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/26 11:55:12 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

t_input	input_check(int argc, char *argv[])
{
	t_input	t_in;

	t_in.error = 0;
	if (argc != 5 && argc != 6)
	{
		t_in.error = -1;
		return (t_in);
	}
	t_in.n = ft_atoi(argv[1], &t_in.error);
	t_in.forks = t_in.n;
	t_in.die = ft_atoi(argv[2], &t_in.error);
	t_in.eat = ft_atoi(argv[3], &t_in.error);
	t_in.sleep = ft_atoi(argv[4], &t_in.error);
	if (t_in.n == 0 || t_in.die == 0)
		t_in.error = -1;
	if (argv[5])
		t_in.each = ft_atoi(argv[5], &t_in.error);
	else
		t_in.each = -1;
	return (t_in);
}

void	ft_usleep(long ms, t_input *t_in)
{
	t_timeval	start;
	t_timeval	now;
	long		time;

	if (gettimeofday(&start, NULL) < 0)
		error_check_kill(-1, "getting time", 12, t_in);
	if (gettimeofday(&now, NULL) < 0)
		error_check_kill(-1, "getting time", 12, t_in);
	time = (now.tv_sec - start.tv_sec) * 1000
		+ (now.tv_usec - start.tv_usec) / 1000;
	while (time < ms)
	{
		if (usleep(900) < 0)
			error_check_kill(-1, "usleep", 6, t_in);
		if (gettimeofday(&now, NULL) < 0)
			error_check_kill(-1, "getting time", 12, t_in);
		time = (now.tv_sec - start.tv_sec) * 1000
			+ (now.tv_usec - start.tv_usec) / 1000;
	}
}

void	ft_print(t_philo *t_p, int par)
{
	sem_wait(t_p->t_inp->print);
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
	sem_post(t_p->t_inp->print);
}
