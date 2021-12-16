#include <stdio.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == 0)
		*lst = new;
	else
		ft_lstadd_back(&((*lst)->next), new);
}

int		main(void)
{
	int		data[4] = {11, 22, 33, 44};
	int		i;
	t_list	*lst;
	t_list	*new;

	lst = ft_lstnew((void *)&data[0]);
	// lst->next = ft_lstnew((void *)&data[1]);
	// lst->next->next = ft_lstnew((void *)&data[2]);
	new = ft_lstnew((void *)&data[3]);
	ft_lstadd_back(&lst, new);
	i = 0;
	while (lst)
	{
		printf("content on p%d is equal to %d\n", i, *(int *)lst->content);
		++i;
		lst = lst->next;
	}
	return (0);
}
