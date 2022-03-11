#include "push_swap.h"

void	ft_push_node(t_node **from, t_node **to)
{
	t_node	*new_head;

	if (from == NULL || *from == NULL)
		return ;
	new_head = NULL;
	if(*from != (*from)->next)
	{
		new_head = (*from)->next;
		new_head->prev = (*from)->prev;
		(*from)->prev->next = new_head;
	}
	if (*to == NULL)
	{
		(*from)->next = *from;
		(*from)->prev = *from;
	}
	else
	{
		(*from)->next = *to;
		(*from)->prev = (*to)->prev;
		(*to)->prev->next = *from;
		(*to)->prev = *from;
	}
	*to = *from;
	*from = new_head;
}

void	ft_swap_node(t_node **node)
{
	t_node	*head;
	t_node	*last;
	t_node	*foll;

	if (!*node || (*node)->next == *node)
		return ;
	if ((*node)->prev == (*node)->next)
	{
		ft_rotate_node(node);
		return ;
	}
	last = (*node)->prev;
	foll = *node;
	head = (*node)->next;
	foll->next = head->next;
	foll->prev = head;
	head->prev = last;
	head->next = foll;
	last->next = head;
	*node = head;
}

void	ft_rotate_node(t_node **node)
{
	if (!*node)
		return ;
	*node = (*node)->next;
}

void	ft_reverse_node(t_node **node)
{
	if (!*node)
		return ;
	*node = (*node)->prev;
}

int		ft_isSorted_node(t_node *stack, int len)
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

int		ft_isSorted_node_r(t_node *stack, int len)
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

int		ft_find_limit(t_data *data)
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

int		ft_chunk_len(t_node *node, int flag)
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
