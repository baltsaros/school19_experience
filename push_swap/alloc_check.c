/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:03:11 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/22 09:42:23 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alloc_check(char **str)
{
	if (!str)
	{
		write(2, "Allocation failed\n", 18);
		exit(1);
	}
	if ((!str[0]))
	{
		write(2, "Invalid arg\n", 12);
		ft_free(str);
		exit(1);
	}
}

void	alloc_check_small(void *str)
{
	if (!str)
	{
		write(2, "Allocation failed\n", 18);
		exit(1);
	}
}

void	alloc_check_node(t_node *new, t_node **node)
{
	if (!new)
	{
		write(2, "Allocation failed\n", 18);
		*node = ft_free_node(*node);
		exit(1);
	}
}
