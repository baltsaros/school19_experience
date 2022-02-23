/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:39:02 by abuzdin           #+#    #+#             */
/*   Updated: 2022/02/23 17:39:05 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_check(int input, char *str, int n)
{
	if (input < 0)
	{
		write(1, str, n);
		perror("something went wrong");
		exit (EXIT_FAILURE);
	}
	return (input);
}
