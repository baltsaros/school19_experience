#include "minishell.h"

// char	*prepare_str(t_input *data)
// {
// 	char	*ret;

// 	while (data->args)
// 	{
// 		data->args = data->args->next;
// 	}
// 	return (ret);
// }

int	yo_pwd(t_input *data)
{
	char	*ret;

	ret = NULL;
	ret = getcwd(NULL, 0);
	if (!ret)
	{
		data->status = 1;
		perror("pwd");
	}
	else
		ft_printf("%s\n", ret);
	return (0);
}

int	yo_cd(t_input *data)
{
	if (!data->argv[1])
		return (0);
	else if (chdir(data->argv[1]))
	{
		data->status = 1;
		perror("cd");
	}
	return (0);
}

int	yo_echo(t_input *data)
{
	int		i;

	i = 1;
	if (!data->argv[1])
		write(1, "\n", 1);
	else if (strncmp(data->argv[1], "-n", 2) == 0)
	{
		++i;
		while (data->argv[i])
		{
			if (ft_strncmp(data->argv[i], "$?", 3) == 0)
			{
				free(data->argv[i]);
				data->argv[i] = ft_strdup(ft_itoa(data->status));
			}
			printf("%s", data->argv[i]);
			++i;
		}
	}
	else
	{
		while (data->argv[i])
		{
			if (ft_strncmp(data->argv[i], "$?", 3) == 0)	// need to merge two tokens for this to work
			{
				free(data->argv[i]);
				data->argv[i] = ft_strdup(ft_itoa(data->status));
			}
			printf("%s", data->argv[i]);
			++i;
		}
		printf("\n");
	}
	return (0);
}

int		yo_export(t_input *data)
{
	t_env	*tmp;
	int		i;

	i = 1;
	tmp = NULL;
	while (data->argv[i])	// need to manage duplicates
	{
		// if (data->argv[i][0] == '=' || check_envp(data->argv[i], data->envp_n, ft_strlen(data->argv[i])))
		// 	++i;
		// if (!data->argv[i])
		// 	break ;
		if (!data->argv[i + 1] || (data->argv[i + 1] && data->argv[i + 1][0] != '='))
			tmp = ft_envp_new(data->argv[i], NULL);
		else if (data->argv[i + 2])
		{
			tmp = ft_envp_new(data->argv[i], data->argv[i + 2]);
			i += 2;
		}
		else
		{
			tmp = ft_envp_new(data->argv[i], ft_strdup(""));
			i += 2;
		}
		++i;
		ft_envp_back(&data->envp_n, tmp);
	}
	if (data->argc > 1)
		return (0);
	tmp = data->envp_n;
	while (tmp)
	{
		if (tmp->value)
			printf("declare -x %s=\"%s\"\n", tmp->type, tmp->value);
		else
			printf("declare -x %s\n", tmp->type);
		tmp = tmp->next;
	}
	return (0);
}

int		yo_env(t_input *data)
{
	t_env	*tmp;

	tmp = data->envp_n;
	if (data->argv[1] && data->argv[1][0] != '|')		// neeed to find a better way to display error
	{
		data->status = 127;
		write(2, "env: ", 5);
		write(2, data->argv[1], ft_strlen(data->argv[1]));
		write(2, ": No such file or directory\n", 28);
		return (data->status);
	}
	printf("env\n");
	while (tmp)
	{
		if (tmp->value)
			printf("%s=%s\n", tmp->type, tmp->value);
		else
			printf("%s\n", tmp->type);
		tmp = tmp->next;
	}
	return (0);
}

int		yo_unset(t_input *data)
{
	t_env	*tmp;
	int		i;

	i = 1;
	tmp = data->envp_n;
	while (data->argv[i])
	{
		if (check_envp(data->argv[i], data->envp_n, ft_strlen(data->argv[i])))
		{
			while (ft_strncmp(data->argv[i], tmp->type, ft_strlen(data->argv[i]) + 1))
			{
				tmp = tmp->next;
			}
			tmp = ft_envp_del(tmp);
		++i;
		}
	}
	return (0);
}

int		yo_exit(t_input *data)
{
	ft_free_envp(data->envp_n);
	ft_free_token(data->args);
	if (data->wild)
		ft_free_token(data->wild);
	printf("exit\n");
	if (data->argv[1])
	{
		data->status = ft_atoi(data->argv[1]);
		exit (data->status);
	}
	exit (data->status);
}
