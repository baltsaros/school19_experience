#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <string.h>

typedef struct s_input
{
	int	n;
	int	f;
	int	die;
	int	eat;
	int	sleep;
	int	each;
	int	error;
}	t_input;

// input_check
t_input	input_check(t_input in, int argc, char *argv[]);

// utils
int		ft_atoi(const char *str, int *error);
t_input	input_check(t_input in, int argc, char *argv[]);
void	error_msg(int nbr);
int		error_check(int nbr);

// philo


#endif