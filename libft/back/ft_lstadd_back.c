#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

// int		main(void)
// {
// 	int		data[4];
// 	int		i;
// 	t_list	*head;
// 	t_list	*current;
// 	t_list	*print;

// 	data[0] = 11;
// 	data[1] = 22;
// 	data[2] = 33;
// 	data[3] = 44;
// 	head = ft_lstnew((void *)&data[0]);
// 	current = ft_lstnew((void *)&data[1]);
// 	ft_lstadd_back(&head, current);
// 	current = ft_lstnew((void *)&data[2]);
// 	ft_lstadd_back(&head, current);
// 	current = ft_lstnew((void *)&data[3]);
// 	ft_lstadd_back(&head, current);
// 	print = head;
// 	i = 0;
// 	while (print)
// 	{
// 		printf("Content on p%d is equal to %d\n", i, *((int *)print->content));
// 		++i;
// 		print = print->next;
// 	}
// 	printf("Last address is %p.\n", (void *)print);
// 	return (0);
// }