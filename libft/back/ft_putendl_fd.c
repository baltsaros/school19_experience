/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:32:48 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:32:49 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		++i;
	}
	write(fd, "\n", 1);
}

// int		main(void)
// {
// 	char	s[] = "Hello world!";
// 	int		fd;

// 	fd = 1;
// 	ft_putendl_fd(s, fd);
// 	return (0);
// }