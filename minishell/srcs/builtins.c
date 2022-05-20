#include "minishell.h"

void	yo_pwd(t_input *data)
{
	char	*ret;

	ret = NULL;
	ret = getcwd(NULL, 0);
	if (!ret)
		perror("pwd");
	else
		ft_printf("%s\n", ret);
	exit ((data->status >> 8) & 0xFF);
}

void	yo_cd(t_input *data)
{
	if (!data->argv[1])
		write(2, "cd: missing an argument\n", 24);
	else if (chdir(data->argv[1]))
		perror("cd");
	return ;
}

void	yo_echo(t_input *data)
{
	ft_printf("%s\n", data->buf + 5);
	exit ((data->status >> 8) & 0xFF);
}

void	yo_export(t_input *data)
{
	exit ((data->status >> 8) & 0xFF);
}

void	yo_env(t_input *data)
{
	exit ((data->status >> 8) & 0xFF);
}

void	yo_unset(t_input *data)
{
	exit ((data->status >> 8) & 0xFF);
}

void	yo_exit(t_input *data)
{
	exit ((data->status >> 8) & 0xFF);
}