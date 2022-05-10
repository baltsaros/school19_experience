// #include "minishell.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>

int	main(int argc, char *argv[], char *env[])
{
	char	*buf;

	while (1)
	{
		buf = readline("yo> ");
		if (buf)
			add_history(buf);
		if (ft_strncmp(buf, "exit", 5) == 0)
		{
			rl_clear_history();
			free(buf);
			exit(0);
		}
	}
	return (0);
}
