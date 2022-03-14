#include "push_swap.c"

void	check_sort(int *array, int length)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 1;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (array[i] > array[j])
				check = 0;
			++j;
		}
		++i;
	}
	if (check)
	{
		write(1, "OK\n", 3);
		exit(EXIT_SUCCESS);
	}
}

void	ft_sort_big_b(t_data *data)
{
	int	limit;

	data->med = ft_find_med_chunk(data->b, data->b->flag);
	if (ft_chunk_len(data->b, data->b->flag) == 1)
	{
		pa(data);
		
	}
	if (data->b->ix < data->med && data->b->next->ix < data->med)
	{
		rb(data);
		++data->rb;
	}
	if (data->b->next->ix > data->med && data->b->next->ix > data->b->ix)
		sb(data);
	if (data->b->ix > data->med)
		pa(data);
	if (data->b->prev->ix > data->b->ix && data->rb)
	{
		rrb(data);
		--data->rb;
	}
	if (data->len_b > 3)
	{
		ft_sort_big_b(data);
		return ;
	}
	ft_sort_three_b(data);
}

void	ft_node_front(t_node **node, t_node *new)
{
	t_node	*last;

	if (!node)
		return ;
	else if (!*node)
		*node = new;
	else
	{
		last = (*node)->prev;
		(*node)->prev = new;
		new->next = *node;
		last->next = *node;
		(*node)->prev = last;
	}
}

t_node	*ft_switch_stack(t_node *one, t_node **two)
{
	t_node	*last;
	t_node	*new_head;

	if (!one || !two)
		return (0);
	else if (!*two && one->next == one)
	{
		*two = one;
		new_head = NULL;
	}
	else if (!*two && one->next != one)
	{
		last = one->prev;
		new_head = one->next;
		new_head->prev = last;
		last->next = new_head;
		one->prev = one;
		one->next = one;
		*two = one;
	}
	else
	{
		last = one->prev;
		new_head = one->next;
		one->prev = one;
		one->next = one;
		new_head->prev = last;
		last->next = new_head;
		(*two)->prev->next = one;
		(*two)->prev = one;
		one->prev = (*two)->prev;
		one->next = *two;
	}
	return (new_head);
}

// int	main(void)
// {
// 	t_node	*node_a;
// 	t_node	*node_b;
// 	t_node	*head;
// 	t_node	*tmp;
// 	int		len_a;
// 	int		len_b;
// 	int		index[5] = {1, 2, 3, 4, 5};
// 	int		number[5] = {9, 4, 12, 77, 11};

	// node_a = ft_node_new(index[0], number[0]);
	// ft_node_print(node_a);
	// tmp = ft_node_new(index[1], number[1]);
	// ft_node_back(&node_a, tmp);
	// tmp = ft_node_new(index[2], number[2]);
	// ft_node_back(&node_a, tmp);
	// node_b = ft_node_new(index[3], number[3]);
	// len_a = ft_node_size(node_a);
	// printf("len_a is %d\n", len_a);
	// len_b = ft_node_size(node_b);
	// printf("len_b is %d\n", len_b);
	// printf("node_a before\n");
	// ft_node_print(node_a);
	// node_a = ft_switch_stack(node_a->prev, &node_b);
	// node_a = ft_node_del(node_a);
	// node_a = ft_free_node(node_a);
	// printf("node_a after\n");
	// printf("node_b\n");
	// ft_node_print(node_b);
// 	return (0);
// }
