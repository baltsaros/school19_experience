#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

// int		main(void)
// {
// 	t_list	*head;
// 	int		data;

// 	data = 11;
// 	head = ft_lstnew((void *)&data);
// 	printf("Content on p1 is equal to %d\n", *((int *)head->content));
// 	return (0);
// }
