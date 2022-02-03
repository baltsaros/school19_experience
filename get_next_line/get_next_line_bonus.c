/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:31:45 by abuzdin           #+#    #+#             */
/*   Updated: 2022/02/03 11:53:17 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_find_line(char *input)
{
	size_t	i;

	i = 0;
	while (input[i] && input[i] != '\n')
		++i;
	return (i);
}

char	*read_line(char *rest, int fd)
{
	ssize_t	r_bytes;
	char	buf[BUFFER_SIZE + 1];

	r_bytes = 1;
	while (!ft_strchr(rest, '\n') && r_bytes > 0)
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes < 0)
			return (0);
		buf[r_bytes] = '\0';
		if (!rest)
		{
			rest = malloc(sizeof(*rest) * 1);
			if (!rest)
				return (0);
			rest[0] = '\0';
		}
		rest = ft_strjoin_free(rest, buf);
	}
	return (rest);
}

char	*get_new_line(char *rest)
{
	char	*ret;
	ssize_t	i;

	if (!rest[0])
		return (0);
	ret = malloc(sizeof(*ret) * (ft_find_line(rest) + 2));
	if (!ret)
		return (0);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		ret[i] = rest[i];
		++i;
	}
	if (rest[i])
	{
		ret[i] = '\n';
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_new_rest(char *rest)
{
	char	*tmp;
	ssize_t	i;
	ssize_t	j;

	i = ft_find_line(rest);
	j = 0;
	if (!rest[i + j])
	{
		free(rest);
		return (0);
	}
	while (rest[i + 1 + j])
		++j;
	tmp = malloc(sizeof(*tmp) * (j + 1));
	if (!tmp)
		return (0);
	j = 0;
	while (rest[i + 1 + j])
	{
		tmp[j] = rest[i + 1 + j];
		++j;
	}
	tmp[j] = '\0';
	free(rest);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	rest[fd] = read_line(rest[fd], fd);
	if (!rest[fd])
		return (0);
	ret = get_new_line(rest[fd]);
	rest[fd] = get_new_rest(rest[fd]);
	return (ret);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	char	*ret;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	int		fd4;
// 	int		fd5;
// 	size_t	i;

// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	fd3 = open("test3.txt", O_RDONLY);
// 	fd4 = open("test4.txt", O_RDONLY);
// 	fd5 = open("test5.txt", O_RDONLY);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("\n++++  ROUND %d  ++++\n", i);
// 		ret = get_next_line(fd1);
// 		printf("ret(fd1) is %s\n", ret);
// 		free(ret);
// 		ret = get_next_line(fd2);
// 		printf("ret(fd2) is %s\n", ret);
// 		free(ret);
// 		ret = get_next_line(fd3);
// 		printf("ret(fd3) is %s\n", ret);
// 		free(ret);
// 		ret = get_next_line(fd4);
// 		printf("ret(fd4) is %s\n", ret);
// 		free(ret);
// 		ret = get_next_line(fd5);
// 		printf("ret(fd5) is %s\n", ret);
// 		free(ret);
// 		++i;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	close(fd4);
// 	close(fd5);
// 	return (0);
// }