/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:40:56 by abuzdin           #+#    #+#             */
/*   Updated: 2022/05/16 15:45:31 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*ft_envp_new(char *type, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	alloc_check_small(node);
	node->type = type;
	node->value = value;
	node->next = node;
	node->prev = node;
	return (node);
}

void	ft_envp_back(t_env **node, t_env *new)
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

t_env	*ft_envp_del(t_env *node)
{
	t_env	*tmp;

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
	free(tmp->type);
	free(tmp->value);
	free(tmp);
	return (node);
}

void	ft_envp_print(t_env *node)
{
	int		i;
	int		len;
	t_env	*head;

	if (!node)
	{
		printf("There are no nodes in the list\n");
		return ;
	}
	head = node;
	i = 0;
	len = ft_envp_size(head);
	printf("===== NODE =====\n");
	while (i < len)
	{
		printf("type for node[%d] is %s\n", i, head->type);
		printf("value for node[%d] is %s\n", i, head->value);
		head = head->next;
		++i;
	}
}

int	ft_envp_size(t_env *node)
{
	int		i;
	t_env	*last;
	t_env	*tmp;

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
