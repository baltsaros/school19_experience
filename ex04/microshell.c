#include "microshell.h"
#include <stdio.h>

void	free_all(t_input *data)
{
	size_t	i;

	i = 0;
	if (data->ctab)
	{
		while (i < data->ncmd)
		{
			free(data->ctab[i].cmds);
			++i;
		}
		free(data->ctab);
	}
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

void	error_check(t_input *data, int param)
{
	if (param < 0)
	{
		error_msg("error: fatal", NULL);
		free_all(data);
		exit(1);
	}
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
}

void	init_struct(t_input *data, char *argv[])
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	data->ctab[j].clen = 0;
	while (argv[i])
	{
		if (!strcmp(argv[i], "|"))
		{
			data->ctab[j].is_pipe = 1;
			j++;
			data->ctab[j].clen = 0;
		}
		else if (!strcmp(argv[i], ";"))
		{
			data->ctab[j].is_semicol = 1;
			j++;
			i++;
			data->ctab[j].clen = 0;
			continue ;
		}
		if (!argv[i])
			break ;
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
		}
		else if (!strcmp(argv[i], ";"))
		{
			data->ctab[j].is_semicol = 1;
			j++;
			i++;
			k = 0;
			continue ;
		}
		if (!argv[i])
			break ;
		data->ctab[j].cmds[k] = argv[i];
		k++;
		i++;
	}
}

void	execute_cmds(t_input *data, char *envp[], t_cmd *ctab)
{
	size_t	i;

	if (ctab->clen == 0)
		return ;
	i = 0;
	// write(2, "cmd: ", 5);
	// write(2, ctab->cmds[0], ft_strlen(ctab->cmds[0]));
	// write(2, "\n", 1);
	if (!strcmp(ctab->cmds[0], "cd"))
	{
		ft_cd(data, ctab);
		return ;
	}
	if (ctab->is_pipe == 1)
		error_check(data, pipe(ctab->fd));
	ctab->pid = fork();
	error_check(data, ctab->pid);
	if (ctab->pid == 0)
	{
		if (ctab->is_pipe == 1)
		{
			error_check(data, dup2(ctab->fd[1], 1));
			close(ctab->fd[1]);
			close(ctab->fd[0]);
		}
		execve(ctab->cmds[0], ctab->cmds, envp);
		{
			error_msg("error: cannot execute", ctab->cmds[0]);
			free_all(data);
			exit(126);
		}
	}
	else
	{
		waitpid(ctab->pid, NULL, 0);
		if (ctab->is_pipe == 1)
		{
			error_check(data, dup2(ctab->fd[0], 0));
			close(ctab->fd[0]);
			close(ctab->fd[1]);
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
		++i;
	}
	free_all(&data);
	return (0);
}
