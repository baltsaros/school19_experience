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

void	ft_fork(char *argv[], char *envp)
{
	int	fd[2];
	int	pid;
	
	error_check(pipe(fd[2]), "In pipe ", 9);
	pid = fork();
	error_check(pid, "In fork ", 9);
	if (pid == 0)
	{
		error_check(dup2(fd[1], STDOUT_FILENO), "In Dup2_ch ", 12);


	}
}

int		main(int argc, char *argv[], char *envp)
{
	int	in;
	int	out;
	int	hd;
	int	i;

	i = 0;
	if (argc > 5)
	{
		if (argv[1] == 0)
		{
			hd = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
			error_check(out, "In Open ", 8);
			// error_check(dup2(hd, STDOUT_FILENO), "In Dup2 her_doc ", 17);
		}
		else
		{
			in = open(argv[1], O_RDONLY);
			out = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
			error_check(dup2(in, STDIN_FILENO), "In Dup2_in ", 12);
			error_check(dup2(out, STDOUT_FILENO), "In Dup2_out ", 13);
			ft_fork(argv, envp);
		}

	}
}