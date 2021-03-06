/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:30:50 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/18 14:23:57 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

// void	ft_clear(void *content)
// {
// 	printf("Deleting %d\n", *((int *)content));
// }

// int		main(void)
// {
// 	int		ar[3];
// 	int		i;
// 	t_list	*head;
// 	t_list	*print;

// 	ar[0] = 11;
// 	ar[1] = 22;
// 	ar[2] = 33;
// 	i = 0;
// 	head = ft_lstnew((void *)&ar[0]);
// 	head->next = ft_lstnew((void *)&ar[1]);
// 	head->next->next = ft_lstnew((void *)&ar[2]);
// 	print = head;
// 	while (print)
// 	{
// 		printf("Content on p%d is equal to %d\n", i, *((int *)print->content));
// 		print = print->next;
// 		++i;
// 	}
// 	printf("Deleting one or more elements...\n");
// 	ft_lstclear(&head->next, &ft_clear);
// 	i = 0;
// 	print = head;
// 	while (print)
// 	{
// 		printf("Content on p%d is equal to %d\n", i, *((int *)print->content));
// 		print = print->next;
// 		++i;
// 	}
// 	return (0);
// }