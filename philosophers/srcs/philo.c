/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:43 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/20 10:24:39 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	check_time(t_philo *t_p)
{
	long	time;

	time = 0;
	gettimeofday(&t_p->t_act, NULL);
	time  = (t_p->t_act.tv_sec - t_p->t_st.tv_sec) * 1000
		+ (t_p->t_act.tv_usec - t_p->t_st.tv_usec) / 1000;
	return (time);
}

int		check_each(t_input *t_in)
{
	int	i;

	i = 0;
	while (i < t_in->n)
	{
		if (t_in->t_p[i].each < t_in->each)
			return (-1);
		++i;
	}
	// if (i == t_in->n)
	return (0);
}

int	check_death(void *args)
{
	t_input		*t_in;
	t_timeval	t_check;
	long		time;
	int			i;

	// printf("check death\n");
	t_in = (t_input *) args;
	i = 0;
	while (1)
	{
		i = (t_in->n + i) % t_in->n;
		gettimeofday(&t_check, NULL);
		time  = (t_check.tv_sec - t_in->t_p[i].t_meal.tv_sec) * 1000
			+ (t_check.tv_usec - t_in->t_p[i].t_meal.tv_usec) / 1000;
		if (((t_check.tv_sec - t_in->t_p[i].t_meal.tv_sec) * 1000
			+ (t_check.tv_usec - t_in->t_p[i].t_meal.tv_usec) / 1000) > t_in->die)
		{
			printf("time is %ld\n", time);
			free_all(t_in);
			ft_print(&t_in->t_p[i], 5);
			// printf("%ld %d died\n", check_time(&t_in->t_p[i]), t_in->t_p[i].p_i);
			return (0);
		}
		if (t_in->each > 0 && check_each(t_in) == 0)
			break ;
		++i;
	}
	// printf("time %ld - die %ld\n", time, t_p->die);
	return (0);
}


void	*philo(void *args)
{
	t_philo	*t_p;

	t_p = (t_philo *) args;
	if ((t_p->p_i % 2) == 0)
		ft_usleep(1);
	while(1)
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
		pthread_create(&t_in.t_p[i].p_thread, NULL, philo, (void *)&t_in.t_p[i]);
		++i;
	}
	// printf("death loop\n");
	pthread_mutex_lock(&t_in.mutex);
	check_death(&t_in);
	pthread_mutex_unlock(&t_in.mutex);
	// printf("free and exit\n");
	// free_all(&t_in);
	return (0);
}

	// printf("n %d, f %d, die %d, eat %d, sleep %d, each %d\n", 
		// in.n, in.f, in.die, in.eat, in.sleep, in.each);
	// printf("seconds: %ld, microseconds %d\n", time.tv_sec + time.tv_usec, time.tv_usec);
		// printf("philo[%d]: left - %d, right - %d\n", i + 1, i + 1, i + t_in->n * (i == 0));
	// printf("n %d, die %d, eat %d, sleep %d, each %d, dead %d\n"
	// 	, t_in->n, t_in->die, t_in->eat, t_in->sleep, t_in->each, t_in->dead);