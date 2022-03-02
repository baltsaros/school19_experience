/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:07:39 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/02 13:47:19 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"

char	*ft_strjoin_free(char *line, char b)
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

int	get_next_line(char **line)
{
	char	buf[1];
	ssize_t	r_bytes;

	*line = ft_calloc(1, sizeof(char));
	if (!line | !*line)
		error_check(-1, "In gnl ", 8);
	r_bytes = 1;
	while (r_bytes > 0)
	{
		r_bytes = read(0, buf, 1);
		if (buf[0] == '\n')
		{
			*line = ft_strjoin_free(*line, buf[0]);
			break ;
		}
		*line = ft_strjoin_free(*line, buf[0]);
	}
	return (r_bytes);
}
