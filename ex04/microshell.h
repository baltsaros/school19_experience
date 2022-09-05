#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

typedef struct s_cmd
{
	char	**cmds;
	int		in;
	int		out;
	int		pid;
	int		fd[2];
	int		clen;
	int		is_pipe;
	int		is_semicol;
}	t_cmd;

typedef struct s_input
{
	size_t	i;
	size_t	j;
	char	*tmp;
	t_cmd	*ctab;
	size_t	ncmd;
}	t_input;

#endif
