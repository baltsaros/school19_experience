#include "../include/minishell.h"

char	*ft_strndup(char const *str, size_t size)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(*dest) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

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

char	*ft_strjoin_free(char *rest, char *buf)
{
	char	*unis;
	size_t	i;
	size_t	j;

	if (!rest || !buf)
		return (0);
	unis = malloc(sizeof(*unis) * (ft_strlen(rest) + ft_strlen(buf) + 1));
	if (!unis)
		return (0);
	i = 0;
	while (rest[i])
	{
		unis[i] = rest[i];
		++i;
	}
	j = 0;
	while (buf[j])
	{
		unis[i + j] = buf[j];
		++j;
	}
	unis[j + i] = '\0';
	free(rest);
	return (unis);
}

char	*ft_charjoin_free(char *line, char b)
{
	size_t	i;
	char	*unis;

	i = 0;
	while (line[i])
		++i;
	unis = malloc(sizeof(*unis) * (i + 2));
	if (!unis)
		return (0);
	i = 0;
	while (line[i])
	{
		unis[i] = line[i];
		++i;
	}
	unis[i] = b;
	unis[i + 1] = 0;
	free(line);
	return (unis);
}

char	**get_address(char *cmd[], char *envp[])
{
	char	**env;
	int		i;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5))
		++i;
	env = ft_split(envp[i] + 5, ':');
	alloc_check(env);
	i = 0;
	while (env[i])
	{
		env[i] = ft_strjoin(env[i], "/");
		env[i] = ft_strjoin(env[i], cmd[0]);
		if (!env[i])
		{
			ft_free(env);
			ft_free(cmd);
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
	while (access(env[i], X_OK) != 0)
	{
		++i;
		if (!env[i + 1])
			break ;
	}
	if (env[i] && access(env[i], X_OK) < 0)
	{
		write(2, "command not found\n", 19);
		ft_free(env);
		ft_free(cmd);
		exit(127);
	}
	ret = ft_strdup(env[i]);
	if (!ret)
		error_check(-1, "In strdup ", 11);
	ft_free(env);
	return (ret);
}

void	ft_execve(char *argv, char *envp[])
{
	char	*path;
	char	**cmd;

	if (!argv || !argv[0])
	{
		write(2, "parse error near ""\n", 19);
		exit(1);
	}
	cmd = ft_split(argv, ' ');
	alloc_check(cmd);
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

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	size_f;

	size_f = ft_strlen(to_find);
	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (j + 1 == size_f)
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	check_charset(char c, char *charset)
{
	unsigned int	i;

	i = 0;
	
	if (!charset)
		return (0);
	while (charset[i])
	{
		if (charset[i] == c)
			return (charset[i]);
		++i;
	}
	return (0);
}

int	check_envp(char *c, t_env *envp_n, int n)
{
	if (!envp_n)
		return (0);
	while (envp_n)
	{
		if (ft_strncmp(c, envp_n->type, n))
			return (1);
		envp_n = envp_n->next;
	}
	return (0);
}