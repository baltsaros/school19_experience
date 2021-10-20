#ifndef DISPLAY_FILE_H
# define DISPLAY_FILE_H

#include <unistd.h>
#include <fcntl.h>

#define ARRAY_SIZE 128
#define ERR_1 "File name missing.\n"
#define ERR_2 "Too many arguments.\n"
#define ERR_3 "Cannot read file.\n"

int		display_file(char *path);
void	ft_putstr_fd(int fd, char *str);

#endif