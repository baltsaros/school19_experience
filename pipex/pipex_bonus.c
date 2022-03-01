/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:59:19 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/01 11:16:31 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_fork(char *argv, char *envp[])
{
	int		fd[2];
	int		pid;

	error_check(pipe(fd), "In pipe ", 9);
	pid = fork();
	error_check(pid, "In fork ", 9);
	if (pid == 0)
	{
		error_check(dup2(fd[1], STDOUT_FILENO), "In Dup2_ch ", 12);
		close(fd[0]);
		ft_execve(argv, envp);
	}
	waitpid(pid, NULL, 0);
	error_check(dup2(fd[0], STDIN_FILENO), "In Dup2_pr ", 12);
	close(fd[1]);
}

static void	ft_heredoc(char *limiter)
{
	char	*line;
	int		fd[2];
	int		pid1;

	error_check(pipe(fd), "In pipe ", 9);
	pid1 = fork();
	error_check(pid1, "In fork ", 9);
	if (pid1 == 0)
	{
		error_check(dup2(fd[1], STDOUT_FILENO), "In Dup2_ch ", 12);
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0)
				exit(1);
			write(1, line, ft_strlen(line));
		}
	}
	waitpid(pid1, NULL, 0);
	close(fd[1]);
	error_check(dup2(fd[0], STDIN_FILENO), "In Dup2_pr ", 12);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	in;
	int	out;
	int	i;

	if (argc < 5)
		error_check(-1, "Invalid argc ", 14);
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
	{
		i = 3;
		out = ft_open(argv[argc - 1], 0);
		ft_heredoc(argv[2]);
	}
	else
	{
		i = 2;
		in = ft_open(argv[1], 1);
		error_check(dup2(in, STDIN_FILENO), "In Dup2_in ", 12);
		out = ft_open(argv[argc - 1], 2);
	}
	while (i < argc - 2)
		ft_fork(argv[i++], envp);
	error_check(dup2(out, STDOUT_FILENO), "In Dup2_out ", 13);
	ft_execve(argv[i], envp);
	return (0);
}
