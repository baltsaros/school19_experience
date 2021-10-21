#ifndef FT_CAT_H
# define FT_CAT_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define SIZE 30000

void	ft_putstr_fd(int fd, char *str);
int		ft_cat(int n, char **files);

#endif