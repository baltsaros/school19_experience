#include "minishell.h"

static char	*ft_strndup(char const *str, size_t size)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(*dest) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

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

void	data_init(t_input *data, int argc, char *argv[], char *envp[])
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->status = 0;
	data->envp_n = NULL;
	create_envp(data, envp);
	// ft_envp_print(data->envp_n);
	// data->envp_n = ft_free_envp(data->envp_n);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_input data;

	if (argc != 1)
		exit(EXIT_FAILURE);
	while (1)
	{
		data.buf = readline("yo> ");
		if (data.buf)
			add_history(data.buf);
		data_init(&data, argc, argv, envp);
		if (ft_strncmp(data.buf, "exit", 5) == 0)
		{
			// rl_clear_history(data.buf);
			free(data.buf);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
