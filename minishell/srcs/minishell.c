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

// void	create_args(t_input *data)
// {
// 	t_node	*tmp;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (data->buf[i])
// 	{

// 	}
// }

void	data_init(t_input *data, char *envp[])
{
	data->envp = envp;
	data->status = 0;
	data->envp_n = NULL;
	data->args = NULL;
	create_envp(data, envp);
	data->argv = ft_split_op(data->buf, ' ');
	data->argc = 0;
	while (data->argv[data->argc])
	{
		// printf("argv[%d] is |%s|\n", data->argc, data->argv[data->argc]);
		++data->argc;
	}
	// create_args(data);
	// data->argc = argc;
	// data->argv = argv;
	// ft_envp_print(data->envp_n);
	// data->envp_n = ft_free_envp(data->envp_n);
	ft_free(data->argv);
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
