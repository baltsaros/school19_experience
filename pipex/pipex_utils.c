/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:37:06 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/01 12:18:08 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_check(int input, char *str, int n)
{
	if (input < 0)
	{
		write(2, str, n);
		perror("something went wrong");
		exit (EXIT_FAILURE);
	}
	return (input);
}

char	**get_address(char *cmd[], char *envp[])
{
	char	**env;
	int		i;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5))
		++i;
	env = ft_split(envp[i], ':');
	i = 1;
	while (env[i])
	{
		env[i] = ft_strjoin(env[i], "/");
		env[i] = ft_strjoin(env[i], cmd[0]);
		if (!env[i])
		{
			ft_free(env);
			error_check(-1, "In ft_strjoin ", 15);
		}
		++i;
	}
	return (env);
}

char	*access_check(char *cmd[], char *envp[])
{
	char	**env;
	int		i;
	char	*ret;

	env = get_address(cmd, envp);
	i = 1;
	while (access(env[i], F_OK) != 0)
	{
		++i;
		if (!env[i + 1])
			break ;
	}
	if (env[i] && access(env[i], F_OK) < 0)
	{
		write(2, "command not found\n", 19);
		ft_free(env);
		exit(127);
	}
	ret = ft_strdup(env[i]);
	ft_free(env);
	return (ret);
}

void	ft_execve(char *argv, char *envp[])
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	path = access_check(cmd, envp);
	if (execve(path, cmd, envp) < 0)
	{
		perror("Execve error");
		ft_free(cmd);
		free(path);
		exit(127);
	}
}

int	ft_open(char *file, int par)
{
	int	fd;

	fd = -1;
	if (par == 0)
	{
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0777);
		error_check(fd, "In Open heredoc ", 17);
	}
	else if (par == 1)
	{
		fd = open(file, O_RDONLY);
		error_check(fd, "In Open in ", 12);
	}
	else if (par == 2)
	{
		fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0777);
		error_check(fd, "In Open out ", 13);
	}
	else
		error_check(-1, "Invalid parameter in ft_open ", 30);
	return (fd);
}
