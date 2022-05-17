/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:07:39 by abuzdin           #+#    #+#             */
/*   Updated: 2022/05/17 13:03:36 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (buf[0] == '\"' || buf[0] == '\'')
		{
			*line = ft_charjoin_free(*line, buf[0]);
			alloc_check_small(*line);
			break ;
		}
		*line = ft_charjoin_free(*line, buf[0]);
		alloc_check_small(*line);
	}
	return (r_bytes);
}
