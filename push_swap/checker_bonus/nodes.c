/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:21:57 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/15 12:09:00 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*ft_node_new(int index, int number)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	alloc_check_small(node);
	node->ix = index;
	node->nb = number;
	node->flag = 0;
	node->next = node;
	node->prev = node;
	return (node);
}

void	ft_node_back(t_node **node, t_node *new)
{
	if (!node || !new)
		return ;
	if (!*node)
		*node = new;
	else
	{
		new->next = *node;
		new->prev = (*node)->prev;
		(*node)->prev->next = new;
		(*node)->prev = new;
	}
}

t_node	*ft_node_del(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return (NULL);
	tmp = node;
	if (tmp == tmp->next)
		node = NULL;
	else if (tmp->prev == tmp->next)
	{
		node = node->next;
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node = node->next;
	}
	free(tmp);
	return (node);
}

void	ft_node_print(t_node *node)
{
	int		i;
	int		len;
	t_node	*head;

	if (!node)
	{
		printf("There are no nodes in the list\n");
		return ;
	}
	head = node;
	i = 0;
	len = ft_node_size(node);
	printf("===== NODE =====\n");
	while (i < len)
	{
		printf("ix for node[%d] is %d, flag is %d\n", i, head->ix, head->flag);
		head = head->next;
		++i;
	}
}

int	ft_node_size(t_node *node)
{
	int		i;
	t_node	*last;
	t_node	*tmp;

	if (!node)
		return (0);
	i = 1;
	tmp = node;
	last = tmp->prev;
	while (tmp != last)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}
