#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>


typedef struct s_flags
{
	int	zero;
	int	minus;
	int	dot;
	int	space;
	int	plus;
	int	sharp;
	int	width;
}	t_flags;

int		ft_printf(const char *str, ...);
void	ft_putnbr_base(int nbr, char *base, int *r);
void	ft_putnbr_base_un(unsigned int nbr, char *base, int *r);
void	ft_putptr_add(long nbr, char *base, int *r);
void	ft_putptr_add_un(unsigned long nbr, char *base, int *r);
void	ft_putchar(char c, int *r);
void	ft_putstr(char *str, int *r);

#endif