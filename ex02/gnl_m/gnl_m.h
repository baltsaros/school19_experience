#ifndef GNL_M_H
# define GNL_M_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(char **line);
size_t	ft_strlen(char *str);
int		ft_strchr(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin_free(char *rest, char *buf);


#endif