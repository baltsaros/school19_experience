#include "push_swap.h"

void	ft_check_a(t_data *data)
{
	int	limit;
	int	chunk;

	while (!ft_sorted_node(data->a, data->len_a))
	{
		chunk = ft_chunk_len(data->a, data->a->flag);
		if (chunk == 2)
		{
			sa(data);
			return ;
		}
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
		++data->iter;
		while (data->rb > 0)
		{
			rra(data);
			--data->rb;
		}
	}
}

void	ft_sort_big_b(t_data *data)
{
	int	chunk;
	int	limit;
	
	while (data->len_b > 3)
	{
		chunk = ft_chunk_len(data->b, data->b->flag);
		if (chunk == 1)
		{
			pa(data);
		}
		else if (chunk == 2)
		{
			if (data->b->ix < data->b->next->ix)
				sb(data);
			pa(data);
			pa(data);
		}
		else
		{
				data->med = ft_find_med_chunk(data->b, data->b->flag);
				limit = ft_find_limit_b(data, data->b->flag);
				while (limit > 0)
				{
					if (data->b->ix <= data->med && limit > 0)
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
				while(data->rb > 0)
				{
					rrb(data);
					--data->rb;
				}
				ft_check_a(data);
		}
	}
}

void	ft_sort_big(t_data *data)
{
	int	limit;
	
	while (data->len_a > 3)
	{
		data->med = ft_find_med(data->a);
		limit = ft_find_limit(data);
		while (limit > 0)
		{
			if (data->a->ix >= data->med)
				ra(data);
			else
			{
				data->a->flag = data->iter;
				pb(data);
				--limit;
			}
		}
		++data->iter;
	}
	ft_sort_three(data);
	ft_sort_big_b(data);
	ft_sort_three_b(data);
	// ft_node_print(data->a);
	// ft_node_print(data->b);
	// printf("chunk size is %d\n", ft_chunk_len(data->b, data->b->flag));
	ft_exit(data, 0);
}
