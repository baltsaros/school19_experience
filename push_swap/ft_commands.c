/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:32:44 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/14 17:34:41 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_node(t_node **from, t_node **to)
{
	t_node	*new_head;

	if (from == NULL || *from == NULL)
		return ;
	new_head = NULL;
	if (*from != (*from)->next)
	{
		new_head = (*from)->next;
		new_head->prev = (*from)->prev;
		(*from)->prev->next = new_head;
	}
	if (*to == NULL)
	{
		(*from)->next = *from;
		(*from)->prev = *from;
	}
	else
	{
		(*from)->next = *to;
		(*from)->prev = (*to)->prev;
		(*to)->prev->next = *from;
		(*to)->prev = *from;
	}
	*to = *from;
	*from = new_head;
}

void	ft_swap_node(t_node **node)
{
	t_node	*head;
	t_node	*last;
	t_node	*foll;

	if (!*node || (*node)->next == *node)
		return ;
	if ((*node)->prev == (*node)->next)
	{
		ft_rotate_node(node);
		return ;
	}
	last = (*node)->prev;
	foll = *node;
	head = (*node)->next;
	foll->next = head->next;
	foll->prev = head;
	head->prev = last;
	head->next = foll;
	last->next = head;
	*node = head;
}

void	ft_rotate_node(t_node **node)
{
	if (!*node)
		return ;
	*node = (*node)->next;
}

void	ft_reverse_node(t_node **node)
{
	if (!*node)
		return ;
	*node = (*node)->prev;
}
