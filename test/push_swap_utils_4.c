/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:05:58 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/15 10:42:01 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_node(t_node *stack, int len)
{
	t_node	*tmp;
	int		i;

	if (!stack)
		return (-1);
	i = 0;
	tmp = stack;
	while (tmp->ix < tmp->next->ix && i < len - 1)
	{
		tmp = tmp->next;
		++i;
	}
	if (i == len - 1)
		return (1);
	else
		return (0);
}

int	ft_sorted_node_r(t_node *stack, int len)
{
	t_node	*tmp;
	int		i;

	if (!stack)
		return (-1);
	i = 0;
	tmp = stack;
	while (tmp->ix > tmp->next->ix && i < len - 1)
	{
		tmp = tmp->next;
		++i;
	}
	if (i == len - 1)
		return (1);
	else
		return (0);
}

int	ft_chunk_len(t_node *node, int flag)
{
	int		i;
	t_node	*last;
	t_node	*tmp;

	if (!node)
		return (0);
	i = 0;
	tmp = node;
	last = tmp->prev;
	while (tmp != last && tmp->flag == flag)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_find_med(t_node *stack)
{
	int		i;
	int		sum;
	int		len;
	t_node	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	len = ft_node_size(tmp);
	sum = 0;
	i = 0;
	while (i < len)
	{
		sum += tmp->ix;
		tmp = tmp->next;
		++i;
	}
	return (sum / i);
}

int	ft_find_med_chunk(t_node *stack, int flag)
{
	int		i;
	int		sum;
	int		len;
	t_node	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	len = ft_chunk_len(stack, flag);
	sum = 0;
	i = 0;
	while (i < len && tmp->flag == flag)
	{
		sum += tmp->ix;
		tmp = tmp->next;
		++i;
	}
	return (sum / i);
}
