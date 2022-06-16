/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:40:56 by abuzdin           #+#    #+#             */
/*   Updated: 2022/06/03 10:05:20 by abuzdin          ###   ########.fr       */
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
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_envp_back(t_env **node, t_env *new)
{
	t_env *tmp;
	
	tmp = NULL;
	if (!node || !new)
		return ;
	if (!*node)
		*node = new;
	else
	{
		tmp = *node;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
}

t_env	*ft_envp_del(t_env *node)
{
	t_env	*tmp;

	if (!node)
		return (NULL);
	tmp = node;
	if (tmp->prev && tmp->next)
	{
		node = node->prev;
		node->next = tmp->next;
		node->next->prev = node;
	}
	else if (tmp->prev)
	{
		node = node->prev;
		node->next = NULL;
	}
	else if (tmp->next)
	{
		node = node->next;
		node->prev = NULL;
	}
	free(tmp->type);
	free(tmp->value);
	free(tmp);
	return (node);
}

void	ft_envp_print(t_env *node)
{
	int		i;

	if (!node)
	{
		printf("There are no envp nodes in the list\n");
		return ;
	}
	i = 0;
	printf("===== ENVP NODE =====\n");
	while (node)
	{
		printf("type for node[%d] is %s\n", i, node->type);
		printf("value for node[%d] is %s\n", i, node->value);
		node = node->next;
		++i;
	}
}

int	ft_envp_size(t_env *node)
{
	int	i;

	if (!node)
		return (0);
	i = 1;
	while (node->next)
	{
		++i;
		node = node->next;
	}
	return (i);
}
