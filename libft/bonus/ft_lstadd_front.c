#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = new;
	(*lst)->next = tmp;
}

int		main(void)
{
	int		a;
	int		b;
	t_list	*head;
	t_list	*current;

	a = 11;
	b = 22;
	head = ft_lstnew((void *)&a);
	current = ft_lstnew((void *)&b);
	head->next = current;
	printf("Content on p1 is equal to %d\n", *((int *)head->content));
	printf("Content on p2 is equal to %d\n", *((int *)head->next->content));
	printf("Pushing the new element to the front...\n");
	ft_lstadd_front(&head, current);
	printf("Content on p1 is equal to %d\n", *((int *)head->content));
	printf("Content on p2 is equal to %d\n", *((int *)head->next->content));
	return (0);
}
