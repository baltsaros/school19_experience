#include "push_swap.h"

void	ft_push(t_node **one, t_node **two)  // from one to two
{
	t_node	*last;
	t_node	*new_head;

	if (!one || !two)
		return ;
	else if (!*two && (*one)->next == *one)
	{
		*two = *one;
		new_head = NULL;
	}
	else if (!*two && (*one)->next != *one)
	{
		last = (*one)->prev;
		new_head = (*one)->next;
		new_head->prev = last;
		last->next = new_head;
		(*one)->prev = *one;
		(*one)->next = *one;
		*two = *one;
	}
	else
	{
		last = (*one)->prev;
		new_head = (*one)->next;
		(*one)->prev = *one;
		(*one)->next = *one;
		new_head->prev = last;
		last->next = new_head;
		(*two)->prev->next = *one;
		(*two)->prev = *one;
		(*one)->prev = (*two)->prev;
		(*one)->next = *two;
	}
}