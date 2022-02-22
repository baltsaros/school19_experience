#include "pipex.h"

int		main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	in;
	int	out;
	int	i;
	int	p;

	i = 0;

	// if (argc != 5)
	// {
	// 	perror("Incorrect amount of arguments");
	// 	return (0);
	// }
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("Fork1 error: ");
		return (pid1);
	}
	if (pid1 == 0)
	{
		in = open(argv[1], O_RDONLY);
		if (in < 0)
		{
			perror("Open1 error: ");
			return (in);
		}
		dup2(in, 0);
		dup2(fd[1], 1);
		p = pipe(fd);
		if (p < 0)
		{
			perror("Pipe error: ");
			return (-1);
		}
		close(fd[0]);
		close(fd[1]);
		close(in);
		execve(argv[0], ft_split(argv[2], ' '), envp);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("Fork2 error: ");
		return (pid2);
	}
	if (pid2 == 0)
	{
		out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC);
		if (out < 0)
		{
			perror ("Open2 error: ");
			return (out);
		}
		dup2(out, 1);
		dup2(fd[0], 0);
		close(fd[0]);
		close(out);
		execve(argv[0], ft_split(argv[2], ' '), envp);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
