#include "minishell.h"

void	ft_fork(char *argv, char *envp[])
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

void	ft_heredoc(char *limiter)
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
			if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0 &&
				ft_strlen(limiter) == (ft_strlen(line) - 1))
			{
				free(line);
				exit(EXIT_SUCCESS);
			}	
			write(1, line, ft_strlen(line));
			free(line);
		}
	}
	waitpid(pid1, NULL, 0);
	close(fd[1]);
	error_check(dup2(fd[0], STDIN_FILENO), "In Dup2_pr ", 12);
}

int	pipex(int argc, char *argv[], char *envp[])
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

int	execute(t_input *data)
{
	int	pid;
	int	i;

	pid = 0;
	i = 0;
	while (i < 7)
	{
		if (ft_strncmp(data->argv[0], data->builtins[i].name, ft_strlen(data->builtins[i].name) + 1))
			++i;
		else
		{
			data->builtins[i].func(data);
			break;
		}
	}
	if (i >= 7)
	{
		pid = fork();
		if (pid == 0)
			ft_execve(data->buf, data->envp);
	}
	waitpid(pid, &data->status, 0);
	return (0);
}
