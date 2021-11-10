#ifndef FT_TAIL_H
# define FT_TAIL_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define SIZE 1024

void	ft_putstr_fd(int fd, char *str);
void	ft_tail(int n, char **files);
int		ft_atoi(char *str);

#endif