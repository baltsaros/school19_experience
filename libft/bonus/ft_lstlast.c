#include <stdio.h>
#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return(lst);
}

int		main(void)
{
	int		data[4] = {11, 22, 33, 44};
	t_list	*elem;
	t_list	*last;
	// int		i;

	// i = 0;
	// while (i < 4)
	// {
	// 	elem = ft_lstnew((void *)&data[i]);
	// 	printf("content on p%d is equal to %d\n", i, *(int *)elem->content);
	// 	++i;
	// 	elem = elem->next;
	// }
	elem = ft_lstnew((void *)&data[0]);
	elem->next = ft_lstnew((void *)&data[1]);
	elem->next->next = ft_lstnew((void *)&data[2]);
	elem->next->next->next = ft_lstnew((void *)&data[3]);
	last = ft_lstlast(elem);
	printf("content on the last p is equal to %d\n", *(int *)last->content);
	printf("content on the last p is equal to %d\n", *(int *)elem->next->next->next->content);
	return (0);
}
