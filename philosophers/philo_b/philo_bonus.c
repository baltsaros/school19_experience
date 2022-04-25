/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:43 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/25 11:30:30y abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	check_time(t_philo *t_p)
{
	long	time;

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

void	*check_death(void *args)
{
	t_timeval	t_check;
	long		time;
	t_philo		*t_p;

	t_p = (t_philo *) args;
	while (1)
	{
		gettimeofday(&t_check, NULL);
		time = ((t_check.tv_sec - t_p->t_meal.tv_sec) * 1000
				+ (t_check.tv_usec - t_p->t_meal.tv_usec) / 1000);
		if (time > t_p->die)
		{
			ft_print(t_p, 5);
			t_p->alive = 0;
			free_all(t_p->t_inp);
		}
		if (t_p->t_inp->each > 0 && t_p->t_inp->each + 1 == t_p->each)
			free_all(t_p->t_inp);
			// exit(EXIT_SUCCESS);
		ft_usleep(1);
	}
}

void	philo(t_philo *t_p)
{
	if ((t_p->p_i % 2) == 0)
		ft_usleep(1);
	if (pthread_create(&t_p->check, NULL, check_death, t_p) < 0)
		exit(EXIT_FAILURE);
	while (1)
	{
		sem_wait(t_p->t_inp->take);
		ft_print(t_p, 1);
		sem_wait(t_p->t_inp->take);
		ft_print(t_p, 1);
		sem_wait(t_p->t_inp->time);
		gettimeofday(&t_p->t_meal, NULL);
		sem_post(t_p->t_inp->time);
		ft_print(t_p, 2);
		ft_usleep(t_p->eat);
		sem_post(t_p->t_inp->take);
		sem_post(t_p->t_inp->take);
		ft_print(t_p, 3);
		ft_usleep(t_p->sleep);
		ft_print(t_p, 4);
	}
	pthread_join(t_p->check, NULL);
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
		if ((t_in.t_p[i].pid = fork()) < 0)
			return (-1);
		if (t_in.t_p[i].pid == 0)
		{
			philo(&t_in.t_p[i]); 
			exit(0);
		}
		++i;
	}
	waitpid(0, NULL, 0);
	// if (pthread_create(&t_in.con, NULL, check_death, &t_in) < 0)
	// 	return (-1);
	// pthread_join(t_in.con, NULL);
	if (t_in.free != 1)
		free_all(&t_in);
	return (0);
}
