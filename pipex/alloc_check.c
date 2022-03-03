/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:03:11 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/03 12:16:28 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	alloc_check(char **str)
{
	if (!str)
	{
		write(2, "Allocation failed\n", 19);
		exit(1);
	}
	if ((!str[0]))
	{
		write(2, "Invalid cmd\n", 13);
		ft_free(str);
		exit(1);
	}
}

void	alloc_check_small(char *str)
{
	if (!str)
	{
		write(2, "Allocation failed\n", 19);
		exit(1);
	}
}
