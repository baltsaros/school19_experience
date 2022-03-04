#include <stdio.h>
#include "pipex.h"

void	ft_doc(char *limiter)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(&line))
	{
		printf("%d: len lim - %zu, len line - %zu\n", i, ft_strlen(limiter), ft_strlen(line));
		if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0 && 
			ft_strlen(limiter) == (ft_strlen(line) - 1))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}	
		write(1, line, ft_strlen(line));
		free(line);
	}
}

int	main(int argc, char *argv[])
{
	ft_doc(argv[2]);
	return (0);
}
