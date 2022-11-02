#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>

typedef struct s_cmd
{
	char	**cmds;
	size_t	clen;
	int		is_semicol;
	int		is_pipe;
	int		fd[2];
	int		pid;
}	t_cmd;

typedef struct s_input
{
	t_cmd	*ctab;
	size_t	ncmd;
}	t_input;

#endif