/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:39:22 by abuzdin           #+#    #+#             */
/*   Updated: 2022/02/24 15:53:21 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char **get_address(char *cmd[], char *envp[])
{
	char **env;
	int i;

	i = 0;
	while (ft_strncmp((const char *)"PATH=", (const char *)envp[i], 5))
		++i;
	env = ft_split((const char *)envp[i], ':');
	i = 1;
	while (env[i])
	{
		env[i] = ft_strjoin((const char *)env[i], "/");
		env[i] = ft_strjoin((const char *)env[i], (const char *)cmd[0]);
		++i;
	}
	return (env);
}

static char *access_check(char *cmd[], char *envp[])
{
	char **env;
	int i;
	char *ret;

	env = get_address(cmd, envp);
	i = 1;
	while (access(env[i], F_OK) != 0)
	{
		++i;
		if (!env[i + 1])
			break;
	}
	// if (env[i] && access(env[i], X_OK) < 0)
	// 	error_check(access(env[i], X_OK), "In Access ", 11);
	ret = ft_strdup(env[i]);
	free(env);
	return (ret);
}

static void child_one(char *argv[], char *envp[], int *fd)
{
	int in;
	char *cmd;
	char **cmd1;

	cmd1 = ft_split(argv[2], ' ');
	in = open(argv[1], O_RDONLY);
	error_check(in, "In Open1 ", 9);
	error_check(dup2(in, STDIN_FILENO), "In Dup2_1_1 ", 12);
	error_check(dup2(fd[1], STDOUT_FILENO), "In Dup2_1_2 ", 12);
	close(fd[0]);
	cmd = access_check(cmd1, envp);
	execve(cmd, cmd1, envp);
	perror("Execve error");
	free(cmd);
	free(cmd1);
	exit(127);
}

static void child_two(char *argv[], char *envp[], int *fd)
{
	int out;
	char *cmd;
	char **cmd2;

	cmd2 = ft_split(argv[3], ' ');
	out = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
	error_check(out, "In Open2 ", 9);
	error_check(dup2(fd[0], STDIN_FILENO), "In Dup2_2_1 ", 12);
	error_check(dup2(out, STDOUT_FILENO), "In Dup2_2_2 ", 12);
	close(fd[1]);
	cmd = access_check(cmd2, envp);
	execve(cmd, cmd2, envp);
	perror("Execve error");
	free(cmd);
	free(cmd2);
	exit(127);
}

int main(int argc, char *argv[], char *envp[])
{
	int fd[2];
	int pid[2];
	int p;
	int status;

	if (argc != 5)
	{
		write(1, "Invalid amount of arguments\n", 29);
		exit(EXIT_FAILURE);
	}
	p = pipe(fd);
	error_check(p, "In Pipe ", 8);
	pid[0] = fork();
	error_check(pid[0], "In Fork1 ", 9);
	if (pid[0] == 0)
		child_one(argv, envp, fd);
	pid[1] = fork();
	error_check(pid[1], "In Fork2 ", 9);
	if (pid[1] == 0)
		child_two(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[1], &status, 0);
	return ((status >> 8) & 0xff);
}
