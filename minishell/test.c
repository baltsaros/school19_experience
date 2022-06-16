#include "include/minishell.h"

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
		printf("strndup\n");
		type = ft_strndup(envp[i], start + 1);
		value = ft_strndup(envp[i] + start + 1, end - start - 1);
		printf("new list\n");
		tmp = ft_envp_new(type, value);
		printf("list back\n");
		ft_envp_back(&data->envp_n, tmp);
		++i;
	}
}

void	data_init(t_input *data, int argc, char *argv[], char *envp[])
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->status = 0;
	data->envp_n = NULL;
	create_envp(data, envp);
	printf("node print\n");
	ft_envp_print(data->envp_n);
	printf("node del\n");
	data->envp_n = ft_free_envp(data->envp_n);
	printf("node print\n");
	ft_envp_print(data->envp_n);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_input	data;
	int		i;

	// data_init(&data, argc, argv, envp);
	i = 0;
	data.argv = ft_split_op("one \" two     \" three \"four\"", ' ');
	while (data.argv[i])
	{
		printf("argv[%d] is |%s|\n", i, data.argv[i]);
		++i;
	}
	ft_free(data.argv);
	// system("leaks out");
	return (0);
}
