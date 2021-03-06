/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:24 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/28 09:46:04 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_params(t_input *t_in, t_philo *t_p)
{
	t_p->n = t_in->n;
	t_p->die = t_in->die;
	t_p->eat = t_in->eat;
	t_p->sleep = t_in->sleep;
	t_p->each = 0;
	t_p->alive = 1;
	t_p->t_st = t_in->t_st;
	if (gettimeofday(&t_p->t_meal, NULL) < 0)
		error_check_exit(-1, "getting time", 12, t_in);
	t_p->t_st = t_in->t_st;
	t_p->t_inp = t_in;
}

int	philo_init(t_input *t_in)
{
	int	i;

	sem_unlink("print");
	sem_unlink("time");
	sem_unlink("take");
	sem_unlink("control");
	t_in->t_p = malloc(sizeof(t_philo) * t_in->n);
	if (!t_in->t_p)
		return (-1);
	t_in->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	t_in->time = sem_open("time", O_CREAT | O_EXCL, 0644, 1);
	t_in->control = sem_open("control", O_CREAT | O_EXCL, 0644, 1);
	t_in->take = sem_open("take", O_CREAT | O_EXCL, 0644, t_in->forks);
	if (gettimeofday(&t_in->t_st, NULL) < 0)
		error_check_exit(-1, "getting time", 12, t_in);
	i = 0;
	while (i < t_in->n)
	{
		set_params(t_in, &t_in->t_p[i]);
		t_in->t_p[i].p_i = i + 1;
		++i;
	}
	return (0);
}
