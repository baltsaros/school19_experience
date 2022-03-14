#include "push_swap.h"

void	ft_sort_three(t_data *data)
{
	data->med = ft_find_med(data->a);
	if (data->a->ix == data->med && data->a->next->ix < data->med)
		sa(data);
	else if (data->a->ix == data->med)
		ra(data);
	if (data->a->ix < data->med && !ft_sorted_node(data->a, data->len_a))
		sa(data);
	if (data->a->ix > data->med)
		ra(data);
	if (!ft_sorted_node(data->a, data->len_a))
		sa(data);
}

void	ft_sort_three_b(t_data *data)
{
	if (data->len_b == 1)
	{
		pa(data);
		return ;
	}
	data->med = ft_find_med(data->b);
	if (data->b->ix > data->med)
		pa(data);
	if (data->b->ix < data->med && data->b->prev->ix > data->med)
		rrb(data);
	if (data->b->ix < data->med && data->b->prev->ix == data->med)
		rb(data);
	if (data->b->ix == data->med && data->b->prev->ix > data->med)
		rrb(data);
	if (data->b->ix == data->med && data->b->next->ix > data->med)
		sb(data);
	if (ft_sorted_node_r(data->b, data->len_b))
	{
		while (data->len_b)
			pa(data);
	}
	else
	{
		ft_sort_three_b(data);
		return ;
	}
}

void	ft_sort_small(t_data *data)
{	
	if (data->len_a == 2)
		sa(data);
	else if (data->len_a == 3)
		ft_sort_three(data);
	else if (data->len_a > 3 && data->len_a < 7)
	{
		while (data->len_a - 3 > 0)
		{
			if (data->a->ix > data->len_a + data->len_b - 3)
				ra(data);
			else
				pb(data);
		}
		ft_sort_three(data);
		ft_sort_three_b(data);
	}
	ft_exit(data, 0);
}
