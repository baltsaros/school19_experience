/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:30:43 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/18 14:36:15 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int		main(void)
{
	int		array[3];
	int		i;
	t_list	*head;
	t_list	*current;
	t_list	*print;

	array[0] = 11;
	array[1] = 22;
	array[2] = 33;
	i = 0;
	head = ft_lstnew((void *)&array[0]);
	current = ft_lstnew((void *)&array[1]);
	head->next = current;
	current = ft_lstnew((void *)&array[2]);
	print = head;
	while (print != NULL)
	{
		printf("Content on p%d is equal to %d\n", i, *((int *)print->content));
		++i;
		print = print->next;
	}
	printf("Pushing a new element to the front...\n");
	ft_lstadd_front(&head, current);
	print = head;
	i = 0;
	while (print != NULL)
	{
		printf("Content on p%d is equal to %d\n", i, *((int *)print->content));
		++i;
		print = print->next;
	}
	return (0);
}