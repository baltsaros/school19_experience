/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:52 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/20 09:48:53 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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