#include "libft.h"

void	ft_addback(t_list **lst, void *content)
{
	t_list	*new;
	t_list	*tmp;

	if (!(*lst) || !content)
		return ;
	new = ft_lstnew(content);
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

// int		main(void)
// {
// 	t_list	*head;
// 	int		a;
// 	int		b;
	
// 	a = 10;
// 	b = 20;
// 	head = ft_lstnew((void *)&a);
// 	ft_addback(&head, (void *)&b);
// 	printf("%d\n", *(int *)head->content);
// 	printf("%d\n", *(int *)head->next->content);
// 	return (0);
// }
