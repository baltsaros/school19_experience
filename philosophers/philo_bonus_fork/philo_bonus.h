/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:47 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/25 11:10:21 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <string.h>
# include <semaphore.h>
# include <signal.h>

typedef struct timeval	t_timeval;

typedef struct s_philo
{
	int				n;
	long			die;
	int				eat;
	int				sleep;
	int				each;
	int				p_i;
	pid_t			pid;
	struct s_input	*t_inp;
	t_timeval		t_meal;
	t_timeval		t_st;
	t_timeval		t_act;
}	t_philo;

typedef struct s_input
{
	int				n;
	long			die;
	int				eat;
	int				sleep;
	int				each;
	int				error;
	int				free;
	sem_t			*print;
	sem_t			*take;
	sem_t			*control;
	sem_t			*time;
	unsigned int	forks;
	t_philo			*t_p;
	t_timeval		t_st;
}	t_input;

// utils
int		ft_atoi(const char *str, int *error);
void	error_msg(int nbr);
void	ft_usleep(long ms);
void	ft_print(t_philo *t_p, int par);
t_input	input_check(int argc, char *argv[]);
int		free_all(t_input *t_in);

// philo_init
void	set_params(t_input *t_in, t_philo *t_p);
int		philo_init(t_input *t_in);

// philo
void	*philo(void *args);
int		check_death(t_input *t_in);
int		check_each(t_input *t_in);
long	check_time(t_philo *t_p);

#endif