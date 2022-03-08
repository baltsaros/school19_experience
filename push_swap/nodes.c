#include "push_swap.h"

t_node	*ft_node_new(int index, int number)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	alloc_check_small(node);
	node->ix = index;
	node->nb = number;
	node->flag = 0;
	node->next = node;
	node->prev = node;
	return (node);
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

void	ft_node_back(t_node **node, t_node *new)
{
	if (!node || !new)
		return ;
	if (!*node)
		*node = new;
	else
	{
		new->next = *node;
		new->prev = (*node)->prev;
		(*node)->prev->next = new;
		(*node)->prev = new;
	}
}

t_node	*ft_node_del(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return (NULL);
	tmp = node;
	if (tmp == tmp->next)
	{
		free(node);
		node = NULL;
		return (node);
	}
	node = node->next;
	node->prev->prev->next = node;
	node->prev = node->prev->prev;
	tmp->next = NULL;
	free(tmp);
	return (node);
}

void	ft_node_print(t_node *node)
{
	int		i;
	int		len;
	t_node	*head;

	if (!node)
	{
		printf("There are no nodes in the list\n");
		return ;
	}
	head = node;
	i = 0;
	len = ft_node_size(head);
	while (i < len)
	{
		printf("ix for node[%d] is %d\n", i, head->ix);
		printf("nb for node[%d] is %d\n", i, head->nb);
		head = head->next;
		++i;
	}
}

int		ft_node_size(t_node *node)
{
	int	i;
	t_node	*head;

	if (!node)
		return (0);
	i = 0;
	head = node;
	head->prev->next = NULL;
	while (head != NULL)
	{
		head = head->next;
		++i;
	}
	return (i);
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
