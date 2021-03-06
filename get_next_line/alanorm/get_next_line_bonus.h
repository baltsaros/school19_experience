/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:45:28 by abuzdin           #+#    #+#             */
/*   Updated: 2022/02/03 18:00:42 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin_free(char *rest, char *buf);
int		ft_strchr(char *s, int c);

#endif