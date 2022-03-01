#include <stdio.h>
#include "pipex.h"

int	main(void)
{
	int	pid;
	int	n;
	int	fd;

	// n = 5;
	// pid = fork();
	// if (pid == 0)
	// {	
	// 	n += 3;
	// 	printf("n is %d\n", n);
	// }
	// wait(NULL);
	// printf("n is %d\n", n);
	fd = 1;
	dup2(fd, 0);
	printf("%d\n", fd);
	return (0);
}
