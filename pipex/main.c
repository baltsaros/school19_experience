#include "pipex.h"

int		error_check(int input, char *str)
{
	if (input < 0)
	{
		perror("Something went wrong");
		exit (EXIT_FAILURE);
	}
	return (input);
}

char	*access_check(char *cmd[], char *envp[])
{
	char	**env;
	int		i;
	char	*ret;

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
	i = 1;
	while (access(env[i], F_OK) != 0)
	{
		// printf("env[%d] is |%s|, access = %d\n", i, env[i], access(env[i], F_OK));
		++i;
		if (!env[i])
			break ;
	}	
	if (env[i] && access(env[i], X_OK) < 0)
		return (0);
	ret = ft_strdup(env[i]);
	free(env);
	return (ret);
}

void	child_one(char *argv[], char *envp[], char *cmd1[], int *fd)
{
	int		in;
	char	*cmd;

	in = open(argv[1], O_RDONLY);
	if (in < 0)
	{
		perror("Open1 error");
		exit (EXIT_FAILURE);
	}
	if (dup2(in, 0) < 0)
	{
		perror("Dup2[in] error");
		exit (EXIT_FAILURE);
	}
	if (dup2(fd[1], 1) < 0)
	{
		perror("Dup2[fd[1]] error");
		exit (EXIT_FAILURE);
	}
	close(fd[0]);
	cmd = access_check(cmd1, envp);
	execve(cmd, cmd1, envp);
	perror("Execve error");
	exit (127);
}

void	child_two(char *argv[], char *envp[], char *cmd2[], int *fd)
{
	int		out;
	char	*cmd;

	out = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (out < 0)
	{
		perror ("Open2 error");
		exit (EXIT_FAILURE);
	}
	if (dup2(fd[0], 0) < 0)
	{
		perror("Dup2[fd[0]] error");
		exit (EXIT_FAILURE);
	}
	if (dup2(out, 1) < 0)
	{
		perror("Dup2[out] error");
		exit (EXIT_FAILURE);
	}
	close(fd[1]);
	cmd = access_check(cmd2, envp);
	execve(cmd, cmd2, envp);
	perror("Execve error");
	exit (127);
}

int		main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		pid1;
	int		pid2;
	int		p;
	int 	status;
	char	**cmd1;
	char	**cmd2;

	if (argc != 5)
	{
		perror("Incorrect amount of arguments");
		exit (EXIT_FAILURE);
	}
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	p = pipe(fd);
	if (p < 0)
	{
		perror("Pipe error");
		exit (EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("Fork1 error");
		exit (EXIT_FAILURE);
	}
	if (pid1 == 0)
		child_one(argv, envp, cmd1, fd);
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("Fork2 error");
		exit (EXIT_FAILURE);
	}
	if (pid2 == 0)
		child_two(argv, envp, cmd2, fd);
	close(fd[0]);
	close(fd[1]);
	// close(out);
	// close(in);
	waitpid(pid2, &status, 0);
	free(cmd1);
	free(cmd2);
	return ((status >> 8) & 0x000000ff);
}
