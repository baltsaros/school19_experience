/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:26:02 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/14 16:45:15 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_exit(t_data *data, int code)
{
	ft_free_node(data->a);
	ft_free_node(data->b);
	exit(code);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}

int	*ft_array_dup(int *old, int *new, int length)
{
	int	i;

	if (!old)
		return (0);
	i = 0;
	while (i < length)
	{
		new[i] = old[i];
		++i;
	}
	return (new);
}
