#include <stdio.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		++size,
		lst = lst->next;
	}
	return (size);
}

int	main(void)
{
	int		data[3] = {11, 22, 33};
	int		size;
	t_list	*lst;

	lst = ft_lstnew((void *)&data[0]);
	lst->next = ft_lstnew((void *)&data[1]);
	lst->next->next = ft_lstnew((void *)&data[2]);
	size = ft_lstsize(lst);
	printf("content on p1 is equal to %d\n", *(int *)lst->content);
	printf("content on p2 is equal to %d\n", *(int *)lst->next->content);
	printf("content on p3 is equal to %d\n", *(int *)lst->next->next->content);
	printf("size of lst is equal to %d\n", size);
	return (0);
}
