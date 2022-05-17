#include "../include/minishell.h"

void	create_envp(t_input *data, char *envp[])
{
	int		i;
	int		start;
	int		end;
	char	*type;
	char	*value;
	t_env	*tmp;

	i = 0;
	while (envp[i])
	{
		start = 0;
		end = 0;
		while (envp[i][start] != '=')
			++start;
		while (envp[i][end])
			++end;
		type = ft_strndup(envp[i], start + 1);
		value = ft_strndup(envp[i] + start, end - start - 1);
		tmp = ft_envp_new(type, value);
		ft_envp_back(&data->envp_n, tmp);
		++i;
	}
}

int		define_token(char *argv)
{
	int	i;

	i = 0;
	if (strncmp(argv, "<", 2) == 0)
		return (REDIR_OUT);
	else if (strncmp(argv, ">", 2) == 0)
		return (REDIR_IN);
	else if (strncmp(argv, "<<", 3) == 0)
		return (REDIR_HD);
	else if (strncmp(argv, ">>", 3) == 0)
		return (REDIR_AP);
	else if (strncmp(argv, "|", 2) == 0)
		return (PIPE);
	else if (strncmp(argv, "$", 2) == 0)
		return (SEPAR);
	else if (argv[0] == '\'')
		return (QUOTE);
	else if (argv[0] == '\"')
		return (QUOTE_D);
	else
		return (WORD);
}

void	create_token(t_input *data)
{
	t_node	*tmp;
	int		i;
	int		type;

	i = 0;
	while (data->argv[i])
	{
		type = define_token(data->argv[i]);
		tmp = ft_token_new(type, data->argv[i]);
		ft_token_back(&data->args, tmp);
		++i;
	}
}

void	data_init(t_input *data, char *envp[])
{
	data->envp = envp;
	data->status = 0;
	data->envp_n = NULL;
	data->args = NULL;
	create_envp(data, envp);
	// ft_envp_print(data->envp_n);
	// data->envp_n = ft_free_envp(data->envp_n);
	data->argv = ft_split_op(data->buf, ' ');
	data->argc = 0;
	while (data->argv[data->argc])
	{
		// printf("argv[%d] is |%s|\n", data->argc, data->argv[data->argc]);
		++data->argc;
	}
	create_token(data);
	ft_token_print(data->args);
	data->args = ft_free_token(data->args);
	// ft_free(data->argv);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_input data;

	if (argc != 1)
		exit(EXIT_FAILURE);
	(void) argv;
	while (1)
	{
		data.buf = readline("yo> ");
		if (data.buf)
			add_history(data.buf);
		data_init(&data, envp);
		if (ft_strncmp(data.buf, "exit", 5) == 0)
		{
			// rl_clear_history(data.buf);
			free(data.buf);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
