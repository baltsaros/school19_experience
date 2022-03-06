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
	t_node	*last;

	if (!node || !new)
		return ;
	else if (!*node)
		*node = new;
	else
	{
		last = (*node)->prev;
		printf("last is %d\n", last->ix);
		(*node)->prev = new;
		new->next = *node;
		last->next = new;
		new->prev = last;
		printf("new is %d\n", new->ix);
	}
}

void	ft_node_del(t_node *node)
{
	t_node	*tmp;
	t_node	*back;

	if (!node)
		return ;
	tmp = node->prev;
	tmp->next = node->next;
	node->next->prev = tmp;
	free(node);
}

void	ft_node_print(t_node *node)
{
	int		i;
	t_node *head;

	if (!node)
	{
		printf("There are no nodes in te list\n");
		return ;
	}
	i = 0;
	head = node;
	while (node->next != head)
	{
		printf("node[%d] is %d\n", i, node->ix);
		node = node->next;
		++i;
	}
	printf("node[%d] is %d\n", i, node->ix);
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

int	main(void)
{
	t_node	*node;
	t_node	*node_b;
	t_node	*head;
	t_node	*tmp;
	int		index[5] = {1, 2, 3, 4, 5};
	int		number[5] = {9, 4, 12, 77, 11};

	node = NULL;
	head = node;
	node = ft_node_new(index[0], number[0]);
	printf("node[0] is %d\n", node->ix);
	if (node->next)
		printf("node->next is %d\n", node->next->ix);
	tmp = ft_node_new(index[1], number[1]);
	ft_node_back(&node, tmp);
	printf("node[1] is %d\n", node->next->ix);
	tmp = ft_node_new(index[2], number[2]);
	ft_node_back(&node, tmp);
	printf("node[2] is %d\n", node->next->next->ix);
	// node_b = ft_node_new(index[3], number[3]);
	node_b = 0;
	// printf("node_b[0] is %d\n", node_b->ix);
	ft_node_print(node);
	node = ft_switch_stack(node->prev, &node_b);
	// ft_node_del(node->prev);
	ft_node_print(node);
	ft_node_print(node_b);
	return (0);
}