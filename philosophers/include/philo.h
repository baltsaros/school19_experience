/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:47 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/20 10:31:44 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <string.h>

typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

typedef struct s_philo
{
	int			n;
	long		die;
	int			eat;
	int			sleep;
	int			each;
	int			dead;
	pthread_t	p_thread;
	int			p_i;
	t_mutex		*left;
	t_mutex		*right;
	t_mutex		print;
	t_timeval	t_meal;
	t_timeval	t_st;
	t_timeval	t_act;
}	t_philo;

typedef struct s_input
{
	int			n;
	long		die;
	int			eat;
	int			sleep;
	int			each;
	int			error;
	int			dead;
	t_philo		*t_p;
	t_mutex		*fm;
	pthread_t	control;
	t_mutex		mutex;
	t_timeval	t_st;
}	t_input;

// input_check
t_input	input_check(int argc, char *argv[]);

// utils
int		ft_atoi(const char *str, int *error);
void	error_msg(int nbr);
void	ft_usleep(long ms);
int		error_check(int nbr);

// philo_init
void	set_params(t_input *t_in, t_philo *t_p);
int		philo_init(t_input *t_in);

// philo
void	*philo(void *args);
int		check_death(void *args);
long	check_time(t_philo *t_p);

int		free_all(t_input *t_in);
void	ft_print(t_philo *t_p, int par);

#endif