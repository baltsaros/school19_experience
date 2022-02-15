#ifndef FTPRINTF_M_H
# define FTPRINTF_M_H

# include <unistd.h>
# include <stdarg.h>

typedef struct	s_par
{
	int	width;
	int	dot;
	int	type;
}	t_par;

int		ft_printf(const char *str, ...);
void	ft_putchar_count(char c, int *ret);
void	ft_output_nbr(int nbr, t_par *params, int *ret);
void	ft_output_str(char *str, t_par *params, int *ret);
void	ft_output_hex(unsigned int nbr, t_par *params, int *ret);
#endif