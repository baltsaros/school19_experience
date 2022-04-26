/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:34:26 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/26 10:59:19 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	free_all(t_input *t_in)
{
	kill(0, 2);
	free(t_in->t_p);
	sem_unlink("take");
	sem_close(t_in->take);
	sem_unlink("time");
	sem_close(t_in->time);
	sem_unlink("print");
	sem_close(t_in->print);
	return (0);
}

void	error_msg(int nbr)
{
	if (nbr < 0)
	{
		printf("ERROR!\n");
		printf("Input should be in the following form:\n");
		printf("./philo <n_of_philos> <time_to_die> <time_to_eat> ");
		printf("<time_to_sleep> [n_of_times_each_philo_should_eat]\n");
		exit(EXIT_FAILURE);
	}
}

void	error_check_exit(int nbr, char *str, size_t len, t_input *t_in)
{
	if (nbr < 0)
	{
		write(2, "Error in ", 9);
		write(2, str, len);
		free(t_in->t_p);
		sem_unlink("take");
		sem_close(t_in->take);
		sem_unlink("time");
		sem_close(t_in->time);
		sem_unlink("print");
		sem_close(t_in->print);
		exit(EXIT_FAILURE);
	}
}

void	error_check_kill(int nbr, char *str, size_t len, t_input *t_in)
{
	if (nbr < 0)
	{
		write(2, "Error in ", 9);
		write(2, str, len);
		free(t_in->t_p);
		sem_unlink("take");
		sem_close(t_in->take);
		sem_unlink("time");
		sem_close(t_in->time);
		sem_unlink("print");
		sem_close(t_in->print);
		kill(0, 2);
	}
}
