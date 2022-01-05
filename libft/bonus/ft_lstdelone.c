#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}

void	del_elem(void *lst)
{
	lst = NULL;
}

int		main(void)
{
	int		ar[3];
	int		i;
	t_list	*head;
	t_list	*print;

	ar[0] = 11;
	ar[1] = 22;
	ar[2] = 33;
	i = 0;
	head = ft_lstnew((void *)&ar[0]);
	head->next = ft_lstnew((void *)&ar[1]);
	head->next->next = ft_lstnew((void *)&ar[2]);
	print = head;
	while (print)
	{
		printf("Content on p%d is equal to %d\n", i, *((int *)print->content));
		print = print->next;
		++i;
	}
	printf("Deleting one element...\n");
	ft_lstdelone(head->next, &del_elem);
	i = 0;
	print = head;
	while (print)
	{
		printf("Content on p%d is equal to %d\n", i, *((int *)print->content));
		print = print->next;
		++i;
	}
	return (0);
}
