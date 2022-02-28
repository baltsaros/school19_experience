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

static char	*access_check(char *cmd[], char *envp[])
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
	ft_free(env);
	return (ret);
}

void	ft_fork(char *argv, char *envp[])
{
	int		fd[2];
	int		pid;
	char	*path;
	char	**cmd;
	
	error_check(pipe(fd), "In pipe ", 9);
	pid = fork();
	error_check(pid, "In fork ", 9);
	if (pid == 0)
	{
		error_check(dup2(fd[1], STDOUT_FILENO), "In Dup2_ch ", 12);
		close(fd[0]);
		cmd = ft_split(argv, ' ');
		path = access_check(cmd, envp);
		execve(path, cmd, envp);
		perror("Execve error");
		ft_free(cmd);
		free(path);
		exit(127);
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
		// printf("%d %d\n", fd[0], fd[1]);
		while (get_next_line(&line))
		{
			if (ft_strncmp((const char *)limiter, (const char *)line, ft_strlen(limiter)) == 0)
				exit(1);
			write(1, line, ft_strlen(line));
		}
	}
	waitpid(pid1, NULL, 0);
	close(fd[1]);
	error_check(dup2(fd[0], STDIN_FILENO), "In Dup2_pr ", 12);
}

int		main(int argc, char *argv[], char *envp[])
{
	int	in;
	int	out;
	int	i;
	char	*path;
	char	**cmd;

	if (argc > 4)
	{
		if (ft_strncmp((const char *)"here_doc", (const char *)argv[1], 9) == 0)
		{
			i = 3;
			out = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
			ft_heredoc(argv[2]);
		}
		else
		{
			i = 2;
			in = open(argv[1], O_RDONLY);
			error_check(dup2(in, STDIN_FILENO), "In Dup2_in ", 12);
			out = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0777);
		}
		while (i < argc - 2)
		{
			ft_fork(argv[i], envp);
			++i;
		}
		cmd = ft_split(argv[i], ' ');
		path = access_check(cmd, envp);
		error_check(dup2(out, STDOUT_FILENO), "In Dup2_out ", 13);
		if (execve(path, cmd, envp) < 0)
		{
			perror("Execve error");
			ft_free(cmd);
			free(path);
			exit(127);
		}
	}
	return (0);
}