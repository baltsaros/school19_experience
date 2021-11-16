#ifndef DOOP_H
# define DOOP_H

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		ft_check_operator(char *o);
void	ft_operation(int a, int b, char *o);

#endif 