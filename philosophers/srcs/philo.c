/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:43 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/21 16:55:13 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	check_time(t_philo *t_p)
{
	long	time;

	time = 0;
	gettimeofday(&t_p->t_act, NULL);
	time = (t_p->t_act.tv_sec - t_p->t_st.tv_sec) * 1000
		+ (t_p->t_act.tv_usec - t_p->t_st.tv_usec) / 1000;
	return (time);
}

int	check_each(t_input *t_in)
{
	int	i;

	i = 0;
	while (i < t_in->n)
	{
		if (t_in->t_p[i].each < t_in->each)
			return (-1);
		++i;
	}
	return (0);
}

int	check_death(t_input *t_in)
{
	t_timeval	t_check;
	int			i;
	long		time;

	i = 0;
	time = 0;
	while (1)
	{
		i = (t_in->n + i) % t_in->n;
		pthread_mutex_lock(&t_in->mutex);
		gettimeofday(&t_check, NULL);
		time = ((t_check.tv_sec - t_in->t_p[i].t_meal.tv_sec) * 1000
				+ (t_check.tv_usec - t_in->t_p[i].t_meal.tv_usec) / 1000);
		pthread_mutex_unlock(&t_in->mutex);
		// if (time > t_in->die)
		if (time > t_in->die && t_check.tv_sec != t_in->t_p[i].t_meal.tv_sec)
		{
			printf("[%d] time is %ld\n", i, time);
			printf("c.tv_sec is %ld, m.tv_sec is %ld\n", t_check.tv_sec * 1000
				, t_in->t_p[i].t_meal.tv_sec * 1000);
			printf("c.tv_usec is %d, m.tv_usec is %d\n", t_check.tv_usec / 1000
				, t_in->t_p[i].t_meal.tv_usec / 1000);
			free_all(t_in);
			ft_print(&t_in->t_p[i], 5);
			return (0);
		}
		if (t_in->each > 0 && check_each(t_in) == 0)
			break ;
		++i;
	}
	return (0);
}

void	*philo(void *args)
{
	t_philo	*t_p;

	t_p = (t_philo *) args;
	if ((t_p->p_i % 2) == 0)
		ft_usleep(2);
	while (1)
	{
		pthread_mutex_lock(t_p->right);
		ft_print(t_p, 1);
		pthread_mutex_lock(t_p->left);
		ft_print(t_p, 1);
		ft_print(t_p, 2);
		gettimeofday(&t_p->t_meal, NULL);
		ft_usleep(t_p->eat);
		pthread_mutex_unlock(t_p->right);
		pthread_mutex_unlock(t_p->left);
		ft_print(t_p, 3);
		ft_usleep(t_p->sleep);
		ft_print(t_p, 4);
	}
}

int	main(int argc, char *argv[])
{
	t_input		t_in;
	int			i;

	t_in = input_check(argc, argv);
	i = philo_init(&t_in);
	if (t_in.error < 0 || i < 0)
	{
		error_msg(-1);
		return (-1);
	}
	i = 0;
	while (i < t_in.n)
	{
		if (pthread_create(&t_in.t_p[i].p_thread, NULL, philo,
				(void *)&t_in.t_p[i]) != 0)
			return (-1);
		++i;
	}
	check_death(&t_in);
	if (t_in.free != 1)
		free_all(&t_in);
	return (0);
}
