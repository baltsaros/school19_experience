#include <stdio.h>
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = (*lst);
	*lst = new;
	(*lst)->next = tmp;
}

int		main(void)
{
	int		a;
	int		b;
	t_list	*elem;

	a = 11;
	b = 22;
	elem = ft_lstnew(&a);
	elem->next = ft_lstnew(&b);
	printf("content on p1 is equal to %d\n", *(int *)elem->content);
	printf("content on p2 is equal to %d\n", *(int *)elem->next->content);
	ft_lstadd_front(&elem, elem->next);
	printf("push b to the front\n");
	printf("content on p1 is equal to %d\n", *(int *)elem->content);
	printf("content on p2 is equal to %d\n", *(int *)elem->next->content);
	return (0);
}
