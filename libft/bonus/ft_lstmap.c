#include "libft.h"
t_list *ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *))
{

}


int		main(void)
{
	int		ar[4];
	int		i;
	t_list	*head;
	t_list	*print;

	i = 0;
	ar[0] = 11;
	ar[1] = 22;
	ar[2] = 33;
	ar[3] = 44;
	head = ft_lstnew((void *)&ar[0]);
	head->next = ft_lstnew((void *)&ar[1]);
	head->next->next = ft_lstnew((void *)&ar[2]);
	head->next->next->next = ft_lstnew((void *)&ar[3]);
	print = head;
	while (print)
	{
		printf("Content on p%d is equal to %d\n", i, *((int *)print->content));
		print = print->next;
		++i;
	}
	printf("Transofrming the content...\n");
	ft_lstiter(head, &ft_multiply_two);
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
