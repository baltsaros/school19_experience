#include "minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_input data;

	if (argc != 1)
		exit(EXIT_FAILURE);
	while (1)
	{
		data.buf = readline("yo> ");
		if (data.buf)
			add_history(data.buf);
		if (ft_strncmp(data.buf, "exit", 5) == 0)
		{
			// rl_clear_history();
			free(data.buf);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
