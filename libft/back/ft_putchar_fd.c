/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:32:43 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:32:44 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int		main(void)
// {
// 	int		fd;

// 	fd = 2;
// 	ft_putchar_fd('a', fd);
// 	ft_putchar_fd('\n', fd);
// 	return (0);
// }