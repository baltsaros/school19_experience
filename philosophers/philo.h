#ifndef PHILO_H
# define PHILO_H


# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <string.h>

typedef pthread_mutex_t	mutex_t;
typedef struct timeval	t_timeval;

typedef struct s_philo
{
	pthread_t	p_thread;
	int			p_i;
	mutex_t		*left;
	mutex_t		*right;
}	t_philo;

typedef struct s_input
{
	int			n;
	int			die;
	int			eat;
	int			sleep;
	int			each;
	int			error;
	int			dead;
	t_philo		*t_p;
	mutex_t		*fm;
	pthread_t	control;
	mutex_t		mutex;
	t_timeval	t_time;
}	t_input;

// input_check
t_input	input_check(t_input in, int argc, char *argv[]);

// utils
int		ft_atoi(const char *str, int *error);
t_input	input_check(t_input in, int argc, char *argv[]);
void	error_msg(int nbr);
int		error_check(int nbr);
void	ft_states(void *args, int philo, int par);

// philo


#endif