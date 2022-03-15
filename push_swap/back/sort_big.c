/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:22:54 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/15 16:13:27 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_a_extra(t_data *data)
{
	int	limit;

	data->med = ft_find_med_chunk(data->a, data->a->flag);
	limit = ft_find_limit_f(data, data->a->flag);
	while (limit > 0)
	{
		if (data->a->ix >= data->med)
		{
			ra(data);
			++data->rb;
		}
		else
		{
			data->a->flag = data->iter;
			pb(data);
			--limit;
		}
	}
}

void	ft_check_a(t_data *data)
{
	int	chunk;

	while (!ft_sorted_node(data->a, data->len_a))
	{
		chunk = ft_chunk_len(data->a, data->a->flag);
		if (chunk == 2)
		{
			sa(data);
			return ;
		}
		ft_check_a_extra(data);
		++data->iter;
		while (data->rb > 0)
		{
			rra(data);
			--data->rb;
		}
	}
}

static void	ft_sort_big_b_extra(t_data *data)
{
	int	limit;

	data->med = ft_find_med_chunk(data->b, data->b->flag);
	limit = ft_find_limit_b(data, data->b->flag);
	while (limit > 0)
	{
		if (data->b->ix <= data->med)
		{
			rb(data);
			++data->rb;
		}
		if (data->b->ix > data->med)
		{
			pa(data);
			--limit;
		}
	}
	while (data->rb > 0)
	{
		rrb(data);
		--data->rb;
	}
	ft_check_a(data);
}

void	ft_sort_big_b(t_data *data)
{
	int	chunk;

	while (data->len_b > 3)
	{
		chunk = ft_chunk_len(data->b, data->b->flag);
		if (chunk == 1)
			pa(data);
		else if (chunk == 2)
		{
			if (data->b->ix < data->b->next->ix)
				sb(data);
			pa(data);
			pa(data);
		}
		else
			ft_sort_big_b_extra(data);
	}
}
