#include <stdio.h>
#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*path;
	char	**cmd;

	if (!argv[1] || !argv[1][0])
	{
		write(2, "parse error near ""\n", 19);
		exit(1);
	}
	cmd = ft_split(argv[1], ' ');
	alloc_check(cmd);
	path = access_check(cmd, envp);
	return (0);
}
