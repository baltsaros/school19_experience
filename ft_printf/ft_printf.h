#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int		ft_printf(const char *, ...);

char	**ft_split(char const *s, char c);
void	ft_putnbr_base(int nbr, char *base);
int		ft_putnbr_base_un(unsigned int nbr, char *base, int r);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif