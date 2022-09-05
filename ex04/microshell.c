#include "microshell.h"
#include <stdio.h>

void	free_all(t_input *data)
{
	write(2, "FREEEEEE\n", 9);
	if (data->ctab)
		free(data->ctab);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		++len;
	return (len);
}

void	error_msg(char *msg, char *arg)
{
	size_t	len;

	len = ft_strlen(msg);
	write(2, msg, len);
	if (arg)
	{
		write(2, " ", 1);
		len = ft_strlen(arg);
		write(2, arg, len);
	}
	write(2, "\n", 1);
}

void	ft_cd(t_input *data, t_cmd *cmd)
{
	if (cmd->clen != 2)
	{
		error_msg("error: cd: bad arguments", NULL);
		free_all(data);
		exit(1);
	}
	if (chdir(cmd->cmds[1]))
	{
		error_msg("error: cd: cannot change directory to", cmd->cmds[1]);
		free_all(data);
		exit(1);
	}
}

int	check_charset(char c, char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

void	*ft_malloc(t_input *data, size_t n)
{
	void	*ptr;

	ptr = malloc(n);
	if (!ptr)
	{
		error_msg("error: fatal", NULL);
		free_all(data);
		exit(1);
	}
	return (ptr);
}

char	*ft_strndup(t_input *data, char *str, size_t n)
{
	size_t	i;
	char	*tmp;

	if (!str)
		return (NULL);
	i = 0;
	tmp = ft_malloc(data, n + 1);
	while (i < n)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strdup(t_input *data, char *str)
{
	size_t	i;
	char	*tmp;

	if (!str)
		return (NULL);
	i = 0;
	tmp = ft_malloc(data, ft_strlen(str) + 1);
	while (str[i])
	{
		tmp[i] = str[i];
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	count_cmds(t_input *data, char *argv[])
{
	size_t	i;

	i = 0;
	data->ncmd = 1;
	while (argv[i])
	{
		if (!strcmp(argv[i], "|") || !strcmp(argv[i], ";"))
			++data->ncmd;
		++i;
	}
	data->ctab = ft_malloc(data, sizeof(t_cmd) * data->ncmd);
	// printf("ncmd is %ld\n", data->ncmd);
}

void	init_struct(t_input *data, char *argv[])
{
	size_t	j;
	size_t	i;
	size_t	k;

	j = 0;
	i = 0;
	data->ctab[j].clen = 0;
	while (argv[i])
	{
		if (!strcmp(argv[i], "|"))
		{
			data->ctab[j].is_pipe = 1;
			j++;
			i++;
			data->ctab[j].clen = 0;
		}
		else if (!strcmp(argv[i], ";"))
		{
			data->ctab[j].is_semicol = 1;
			j++;
			i++;
			data->ctab[j].clen = 0;
		}
		data->ctab[j].clen++;
		data->ctab[j].is_pipe = 0;
		data->ctab[j].is_semicol = 0;
		i++;
	}
	j = 0;
	while (j < data->ncmd)
	{
		data->ctab[j].cmds = ft_malloc(data, sizeof(char *) * (data->ctab[j].clen + 1));
		data->ctab[j].cmds[data->ctab[j].clen] = NULL;
		++j;
	}
}

void	create_cmds(t_input *data, char *argv[])
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (argv[i])
	{
		if (!strcmp(argv[i], "|"))
		{
			data->ctab[j].is_pipe = 1;
			j++;
			i++;
			k = 0;
			printf("\n");
		}
		else if (!strcmp(argv[i], ";"))
		{
			data->ctab[j].is_semicol = 1;
			j++;
			i++;
			printf("\n");
			k = 0;
		}
		data->ctab[j].cmds[k] = argv[i];
		printf("%s ", data->ctab[j].cmds[k]);
		k++;
		i++;
	}
	printf("\n");
}

void	execute_cmds(t_input *data, char *envp[], t_cmd *ctab)
{
	size_t	i;
	int		ret;

	i = 0;
	if (ctab->is_pipe == 1)
	{
		ret = pipe(ctab->fd);
		if (ret < 0)
		{
			error_msg("error: fatal", NULL);
			free_all(data);
			exit(1);
		}
		ctab->pid = fork();
		if (ctab->pid < 0)
		{
			error_msg("error: fatal", NULL);
			free_all(data);
			exit(1);
		}
		else if (ctab->pid == 0)
		{
			
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_input	data;
	size_t	i;

	if (argc < 2)
	{
		error_msg("Invalid amount of arguments!", NULL);
		return (-1);
	}
	count_cmds(&data, argv + 1);
	init_struct(&data, argv + 1);
	create_cmds(&data, argv + 1);
	i = 0;
	while (i < data.ncmd)
	{
		execute_cmds(&data, envp, &data.ctab[i]);
	}
	return (0);
}
