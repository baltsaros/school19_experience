/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:39:22 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/07 17:47:25 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_one(char *argv[], char *envp[], int *fd)
{
	int	in;

	in = open(argv[1], O_RDONLY);
	error_check(in, "In Open1 ", 9);
	error_check(dup2(in, STDIN_FILENO), "In Dup2_1_1 ", 12);
	error_check(dup2(fd[1], STDOUT_FILENO), "In Dup2_1_2 ", 12);
	close(fd[0]);
	ft_execve(argv[2], envp);
}

static void	child_two(char *argv[], char *envp[], int *fd)
{
	int	out;

	out = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
	error_check(out, "In Open2 ", 10);
	error_check(dup2(fd[0], STDIN_FILENO), "In Dup2_2_1 ", 12);
	error_check(dup2(out, STDOUT_FILENO), "In Dup2_2_2 ", 12);
	close(fd[1]);
	ft_execve(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	pid[2];
	int	p;
	int	status;

	if (argc != 5)
	{
		write(2, "Invalid amount of arguments\n", 29);
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
