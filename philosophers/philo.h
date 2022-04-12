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
typedef struct s_input
{
	int			n;
	int			f;
	int			die;
	int			eat;
	int			sleep;
	int			each;
	int			error;
	pthread_t	*p;
	mutex_t		*fm;
	pthread_t	control;
	mutex_t		mutex;
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