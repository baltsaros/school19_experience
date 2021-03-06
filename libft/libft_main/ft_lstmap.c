/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:31:10 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/19 10:19:40 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*lst_new_head;

	if ((!lst) || (!f))
		return (NULL);
	lst_new_head = ft_lstnew(f(lst->content));
	lst_new = lst_new_head;
	lst = lst->next;
	while (lst)
	{
		lst_new->next = ft_lstnew(f(lst->content));
		if (!(lst_new->next))
		{
			ft_lstclear(&lst_new_head, del);
			return (NULL);
		}
		lst = lst->next;
		lst_new = lst_new->next;
	}
	return (lst_new_head);
}

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*tmp;

// 	if (!(*lst) || !del)
// 		return ;
// 	while (*lst != NULL)
// 	{
// 		tmp = (*lst)->next;
// 		(*del)((*lst)->content);
// 		free(*lst);
// 		*lst = tmp;
// 	}
// }

// void *		lstmap_f(void *content) {
// 	(void)content;
// 	return ("OK !");
// }

void	*ft_multiply_two(void *content)
{
	int	initial;

	initial = *(int *)content;
	*(int *)content = *(int *)content * 2;
	printf("%d multiplied by two is %d\n", initial, *(int *)content);
	return (content);
}

void	del(void *content)
{
	printf("Content is %d\n", *((int *)content));
}

// int		main(void)
// {
// 		t_list	*l = ft_lstnew(strdup(" 1 2 3 "));
// 		t_list	*ret;

// 		l->next = ft_lstnew(strdup("ss"));
// 		l->next->next = ft_lstnew(strdup("-_-"));
// 		ret = ft_lstmap(l, lstmap_f, NULL);
// 	return (0);
// }

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