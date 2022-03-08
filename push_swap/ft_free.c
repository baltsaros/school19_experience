/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:06:30 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/08 10:30:01 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*ft_free_node(t_node *node)
{
	int		len;
	int		i = 0;
	
	if (!node)
		return (NULL);
	i = 0;
	len = ft_node_size(node);
	while (i < len)
	{
		node = ft_node_del(node);
		++i;
	}
	node = NULL;
	return (node);
}