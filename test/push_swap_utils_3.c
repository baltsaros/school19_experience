/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:05:06 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/15 10:05:25 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_limit_f(t_data *data, int flag)
{
	int		ret;
	int		i;
	t_node	*tmp;

	if (!data)
		return (-1);
	i = 0;
	ret = 0;
	tmp = data->a;
	while (i < data->len_a && data->a->flag == flag)
	{
		if (tmp->ix < data->med)
			++ret;
		++i;
		tmp = tmp->next;
	}
	return (ret);
}

int	ft_find_limit(t_data *data)
{
	int		ret;
	int		i;
	t_node	*tmp;

	if (!data)
		return (-1);
	i = 0;
	ret = 0;
	tmp = data->a;
	while (i < data->len_a)
	{
		if (tmp->ix < data->med)
			++ret;
		++i;
		tmp = tmp->next;
	}
	return (ret);
}

int	ft_find_limit_b(t_data *data, int flag)
{
	int		ret;
	int		i;
	t_node	*tmp;

	if (!data)
		return (-1);
	i = 0;
	ret = 0;
	tmp = data->b;
	while (i < data->len_b && flag == data->b->flag)
	{
		if (tmp->ix > data->med)
			++ret;
		++i;
		tmp = tmp->next;
	}
	return (ret);
}
