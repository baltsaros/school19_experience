#include "push_swap.h"

int	ft_find_med(t_node *stack)
{
	int		i;
	int		sum;
	int		len;
	t_node *tmp;

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
	t_node *tmp;

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

t_data	*ft_init_data(t_node *stack)
{
	t_data	*data;

	data->a = stack;
	data->b = NULL;
	data->len_a = ft_node_size(stack);
	data->len_b = 0;
	data->min = 1;
	data->med = ft_find_med(data->a);
	data->iter = 1;
	data->rb = 0;
	return (data);
}

void	ft_sort_three(t_data *data)
{
	data->med = ft_find_med(data->a);
	if (data->a->ix == data->med && data->a->next->ix < data->med)
		sa(data);
	else if (data->a->ix == data->med)
		ra(data);
	if (data->a->ix < data->med && !ft_isSorted_node(data->a, data->len_a))
		sa(data);
	if (data->a->ix > data->med)
		ra(data);
	if (!ft_isSorted_node(data->a, data->len_a))
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
	if (data->b->ix == data->med && data->a->next->ix > data->med)
		sb(data);
	if (data->b->ix == data->med && !ft_isSorted_node_r(data->b, data->len_b))
		rrb(data);
	if (ft_isSorted_node_r(data->b, data->len_b))
	{
		while (data->len_b)
			pa(data);
	}
	else
		ft_sort_three_b(data);
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
	// ft_node_print(data->a);
	ft_exit(data, 0);
}

void	ft_check_a(t_data *data)
{
	int	limit;

	if (ft_isSorted_node(data->a, data->len_a))
		return ;
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
			data->a->flag += data->iter;
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
	ft_sort_big_b(data);
}

void	ft_sort_big_b(t_data *data)
{
	int	chunk;

	data->med = ft_find_med_chunk(data->b, data->b->flag);
	chunk = ft_chunk_len(data->b, data->b->flag);
	while (chunk > 0 && data->len_b > 3)
	{
		if (chunk == 1)
		{
			pa(data);
			--chunk;
		}
		else if (chunk == 2)
		{
			if (data->b->ix < data->b->next->ix)
				sb(data);
			pa(data);
			pa(data);
			chunk -= 2;
		}
		else
		{
			while (data->b->ix <= data->med)
			{
				rb(data);
				++data->rb;
			}
			// if (data->b->next->ix > data->med)
			// 	sb(data);
			while (data->b->ix > data->med)
			{
				pa(data);
				--chunk;
			}
		}
	}
	while(data->rb > 0)
	{
		rrb(data);
		--data->rb;
	}
	ft_check_a(data);
	if (data->len_b > 3)
	{
		ft_sort_big_b(data);
		return ;
	}
	ft_sort_three_b(data);
}

void	ft_sort_big(t_data *data)
{
	int	limit;
	
	data->med = ft_find_med(data->a);
	limit = ft_find_limit(data);
	while (limit > 0)
	{
		if (data->a->ix >= data->med)
			ra(data);
		else
		{
			data->a->flag += data->iter;
			pb(data);
			--limit;
		}
	}
	++data->iter;
	if (data->len_a <= 3)
		ft_sort_three(data);
	if (data->len_a > 3)
	{
		ft_sort_big(data);
		return ;
	}
	ft_node_print(data->b);
	ft_sort_big_b(data);
	// ft_node_print(data->a);
	// printf("chunk size is %d\n", ft_chunk_len(data->b, data->b->flag));
	// ft_sort_big_b(data);
	ft_exit(data, 0);
}

void	ft_sort(t_data *data)
{
	if (data->len_a < 7)
		ft_sort_small(data);
	else
		ft_sort_big(data);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_data	*data;
	int		*array;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		stack_a = ft_argv_split(argc, argv[1]);
	else
		stack_a = input_check(argc, argv);
	data = ft_init_data(stack_a);
	ft_sort(data);
	// printf("med is %d\n", data->med);
	return (0);
}
