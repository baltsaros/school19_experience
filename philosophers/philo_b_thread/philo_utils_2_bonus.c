/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:34:26 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/22 13:44:21 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	free_all(t_input *t_in)
{
	int	i;

	i = 0;
	t_in->free = 1;
	while (i < t_in->n)
	{
		pthread_detach(t_in->t_p[i].p_thread);
		++i;
	}
	kill(0, 2);
	free(t_in->t_p);
	sem_unlink("take");
	sem_close(t_in->take);
	sem_unlink("time");
	sem_close(t_in->time);
	sem_unlink("control");
	sem_close(t_in->control);
	sem_unlink("print");
	sem_close(t_in->print);
	return (0);
}

t_input	input_check(int argc, char *argv[])
{
	t_input	t_in;

	t_in.error = 0;
	t_in.free = 0;
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
