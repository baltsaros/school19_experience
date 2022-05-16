/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:06:30 by abuzdin           #+#    #+#             */
/*   Updated: 2022/05/16 15:45:48 by abuzdin          ###   ########.fr       */
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
	int	len;
	int	i ;

	if (!node)
		return (NULL);
	i = 0;
	len = ft_token_size(node);
	while (i < len)
	{
		node = ft_token_del(node);
		++i;
	}
	node = NULL;
	return (node);
}

t_env	*ft_free_envp(t_env *node)
{
	int	len;
	int	i ;

	if (!node)
		return (NULL);
	i = 0;
	len = ft_envp_size(node);
	// printf("num to delete is %d\n", len);
	while (i < len)
	{
		node = ft_envp_del(node);
		// printf("del num is %d\n", i);
		++i;
	}
	node = NULL;
	return (node);
}
