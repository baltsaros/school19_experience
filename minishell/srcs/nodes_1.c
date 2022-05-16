/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:36:47 by abuzdin           #+#    #+#             */
/*   Updated: 2022/05/16 15:45:13 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_node	*ft_token_new(int type, char *value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	alloc_check_small(node);
	node->type = type;
	node->value = value;
	node->next = node;
	node->prev = node;
	return (node);
}

void	ft_token_back(t_node **node, t_node *new)
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

t_node	*ft_token_del(t_node *node)
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
	free(tmp->value);
	free(tmp);
	return (node);
}

void	ft_token_print(t_node *node)
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
	len = ft_token_size(head);
	printf("===== NODE =====\n");
	while (i < len)
	{
		printf("type for node[%d] is %d\n", i, head->type);
		printf("value for node[%d] is %s\n", i, head->value);
		head = head->next;
		++i;
	}
}

int	ft_token_size(t_node *node)
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
