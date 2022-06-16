/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:37:31 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/05/19 13:37:36 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_cell_back(t_cell **node, t_cell *new)
{
	t_cell	*end;

	end = *node;
	if (!node || !new)
		return ;
	if (!node)
		*node = new;
	else
	{
		while (end)
			end = end->next;
		new->next = NULL;
		end->next = new;
		new->prev = end;
	}
}

void	ft_cell_add_cmd(t_cell	*cell, t_node	*cmd)
{
	ft_token_back(cell->cmds, cmd);
}