#include "minishell.h"

void	yo_pwd(t_input *data)
{
	exit ((data->status >> 8) & 0xFF);
}

void	yo_cd(t_input *data)
{
	printf("ENTERING CD FUNC\n");
	if (!data->argv[1])
		write(2, "cd: missing an argument\n", 24);
	else if (chdir(data->argv[1]))
		perror("cd");
}

void	yo_echo(t_input *data)
{
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