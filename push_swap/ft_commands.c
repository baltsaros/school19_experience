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
	t_node	*new_head;
	t_node	*last;

	if ((*node)->next == *node)
		return ;
	new_head = (*node)->next;
	last = (*node)->prev;
	(*node)->next = new_head->next;
	(*node)->prev = new_head;
	last->next = new_head;
	new_head->next->prev = *node;
	new_head->prev = last;
	new_head->next = *node;
	*node = new_head;
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
