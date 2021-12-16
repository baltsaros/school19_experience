#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	if (!(elem = (t_list *)malloc(sizeof(elem))))
		return (NULL);
	elem->content = content;
	elem->next = 0;
	return (elem);
}

// int		main(void)
// {
// 	int		n;
// 	t_list	*elem;

// 	n = 11;
// 	elem = ft_lstnew((void *)&n);
// 	printf("n in the elem is equal %d\n", *(int *)elem->content);
// 	return (0);
// }
