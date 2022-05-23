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
	int		size;
	int		i;

	i = 0;
	size = ft_token_size(data->args);
	// printf("argv[1] is %s\n", data->argv[1]);
	if (!data->argv[1])
		write(1, "\n", 1);
	else if (strncmp(data->argv[1], "-n", 3) == 0)
		ft_printf("%s", data->buf + 8);
	else
		ft_printf("%s\n", data->buf + 5);
	return (0);
}

int		yo_export(t_input *data)
{
	data->status = 0;
	return (0);
}

int		yo_env(t_input *data)
{
	data->status = 0;
	return (0);
}

int		yo_unset(t_input *data)
{
	data->status = 0;
	return (0);
}

int		yo_exit(t_input *data)
{
	data->status = 0;
	exit (0);
}