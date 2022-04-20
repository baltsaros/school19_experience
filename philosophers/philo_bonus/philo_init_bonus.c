/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:24 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/20 12:44:48 by abuzdin          ###   ########.fr       */
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
	t_p->t_st = t_in->t_st;
	gettimeofday(&t_p->t_meal, NULL);
	t_p->t_st = t_in->t_st;
}

int	philo_init(t_input *t_in)
{
	int	i;

	t_in->t_p = malloc(sizeof(t_philo) * t_in->n);
	t_in->fm = malloc(sizeof(t_mutex) * t_in->n);
	if (!t_in->t_p || !t_in->fm)
		return (-1);
	gettimeofday(&t_in->t_st, NULL);
	i = 0;
	while (i < t_in->n)
	{
		set_params(t_in, &t_in->t_p[i]);
		if (pthread_mutex_init(&t_in->fm[i], NULL) != 0
			|| pthread_mutex_init(&t_in->t_p[i].print, NULL) != 0)
			return (-1);
		if (t_in->n > 1)
			t_in->t_p[i].right = &t_in->fm[(t_in->n + i + 1) % t_in->n];
		else
			t_in->t_p[i].right = &t_in->fm[i];
		t_in->t_p[i].left = &t_in->fm[i];
		t_in->t_p[i].p_i = i + 1;
		++i;
	}
	if (pthread_mutex_init(&t_in->mutex, NULL) != 0)
		return (-1);
	return (0);
}
