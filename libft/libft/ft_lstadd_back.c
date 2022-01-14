/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:30:39 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/14 10:18:00 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
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

// int	main(void)
// {
// 	t_list		*begin;
// 	t_list		*elem;
// 	t_list		*elem2;
// 	t_list		*elem3;
// 	t_list		*elem4;
// 	char		*str = strdup("lorem");
// 	char		*str2 = strdup("ipsum");
// 	char		*str3 = strdup("dolor");
// 	char		*str4 = strdup("sit");

// 	elem = ft_lstnew(str);
// 	elem2 = ft_lstnew(str2);
// 	elem3 = ft_lstnew(str3);
// 	elem4 = ft_lstnew(str4);
// 	begin = NULL;
// 	ft_lstadd_back(&begin, elem);
// 	ft_lstadd_back(&begin, elem2);
// 	ft_lstadd_back(&begin, elem3);
// 	ft_lstadd_back(&begin, elem4);
// 	while (begin)
// 	{
// 		ft_print_result(begin);
// 		begin = begin->next;
// 	}
// 	return (0);
// }