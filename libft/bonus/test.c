#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!(*lst) || !del)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

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

t_list *ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*lst_new_head;

	if ((!lst) || (!f) || (!del))
		return (NULL);
	lst_new_head = ft_lstnew(lst->content);
	lst_new = lst_new_head;
	while (lst->next)
	{
		if (!lst_new)
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		f(lst_new->content);
		lst = lst->next;
		ft_addback(&lst_new, lst->content);
		// lst_new = lst_new->next;
	}
	f(lst_new->content);
	return (lst_new_head);
}

void	ft_multiply_two(void *content)
{
	int	multiply;

	multiply = *(int *)content * 2;
	printf("%d multiplied by two is %d\n", *(int *)content, multiply);
}

// void	ft_multiply_two(void *content)
// {
// 	int	initial;

// 	initial = *(int *)content;
// 	content = *(int *)content * 2;
// 	printf("%d multiplied by two is %d\n", initial, *(int *)content);
// }

void	del(void *content)
{
	printf("Content is %d\n", *((int *)content));
}

int		main(void)
{
	int		ar[4];
	int		i;
	t_list	*head;
	t_list	*print;
	t_list	*new;

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
	new = ft_lstmap(head, &ft_multiply_two, &del);
	i = 0;
	print = new;
	while (print)
	{
		printf("Content on p%d is equal to %d\n", i, *((int *)print->content));
		print = print->next;
		++i;
	}
	return (0);
}
