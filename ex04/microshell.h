#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>

typedef struct s_cmd
{
	char	**cmds;
	int		pid;
	int		fd[2];
	int		clen;
	int		is_pipe;
	int		is_semicol;
}	t_cmd;

typedef struct s_input
{
	t_cmd	*ctab;
	size_t	ncmd;
}	t_input;

#endif
