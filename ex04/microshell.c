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
}

int	main(int argc, char *argv[], char *envp[])
{
	t_input	data;
	if (argc < 2)
	{
		error_msg("Invalid amount of arguments!", NULL);
		return (-1);
	}
	count_cmds(&data, argv);
	printf("ncmd is %ld\n", data.ncmd);
	return (0);
}