/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:06:30 by abuzdin           #+#    #+#             */
/*   Updated: 2022/06/02 17:46:29 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_free(char *str[])
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
}

t_node	*ft_free_token(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = ft_token_del(node);
	node = ft_token_del(node);
	node = NULL;
	return (node);
}

t_env	*ft_free_envp(t_env *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = ft_envp_del(node);
	node = ft_envp_del(node);
	node = NULL;
	return (node);
}
