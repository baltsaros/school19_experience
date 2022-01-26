#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include "libft/libft.h"


typedef struct s_par
{
	int	zero;
	int	minus;
	int	dot;
	int	space;
	int	plus;
	int	sharp;
	int	width;
	int	type;
}	t_par;

int		ft_printf(const char *str, ...);
void	ft_putnbr_base(int nbr, char *base, int *r);
void	ft_putnbr_base_un(unsigned int nbr, char *base, int *r);
void	ft_putptr_add(long nbr, char *base, int *r);
void	ft_putptr_add_un(unsigned long nbr, char *base, int *r);
void	ft_putchar(char c, int *r);
void	ft_putstr(char *str, int *r);
void	ft_output_char(t_par *params, char c, int *r);
void	ft_output_nbr(t_par *params, int nbr, int *r);
void	ft_output_str(t_par *params, char *str, int *r);
void	ft_output_nbr_un(t_par *params, unsigned int nbr, int *r);


#endif