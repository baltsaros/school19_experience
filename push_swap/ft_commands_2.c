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

int	ft_chunk_len(t_node *node, int flag)
{
	int	i;
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
