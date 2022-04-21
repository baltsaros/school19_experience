/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:34:26 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/21 15:10:32 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	free_all(t_input *t_in)
{
	int	i;

	// printf("freeing\n");
	i = 0;
	t_in->free = 1;
	while (i < t_in->n)
	{
		kill t_in->t_p[i].pid;
		// printf("thread %d was freed\n", i);
		++i;
	}
	// printf("unlinking and closing\n");
	sem_unlink("take");
	sem_close(t_in->take);
	free(t_in->t_p);
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
	t_in.forks = t_in.n / 2;
	// printf("pair of forks: %d\n", t_in.forks);
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
