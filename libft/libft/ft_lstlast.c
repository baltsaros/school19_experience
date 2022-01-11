/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:31:04 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/11 11:37:44 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int		main(void)
// {
// 	int		data[4] = {11, 22, 33, 44};
// 	t_list	*elem;
// 	t_list	*last;
// 	// int		i;

// 	// i = 0;
// 	// while (i < 4)
// 	// {
// 	// 	elem = ft_lstnew((void *)&data[i]);
// 	// 	printf("content on p%d is equal to %d\n", i, *(int *)elem->content);
// 	// 	++i;
// 	// 	elem = elem->next;
// 	// }
// 	elem = ft_lstnew((void *)&data[0]);
// 	elem->next = ft_lstnew((void *)&data[1]);
// 	elem->next->next = ft_lstnew((void *)&data[2]);
// 	elem->next->next->next = ft_lstnew((void *)&data[3]);
// 	last = ft_lstlast(elem);
// 	printf("content on the last p is equal to %d\n", *(int *)last->content);
// 	printf("content on the last p is equal to %d\n", *(int *)elem->next->next->next->content);
// 	return (0);
// }

// int	main(void)
// {
// 	t_list		*begin;
// 	t_list		*last;
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
// 	begin = elem;
// 	begin->next = elem2;
// 	begin->next->next = elem3;
// 	begin->next->next->next = elem4;
// 	last = ft_lstlast(begin);
// 	printf("content on the last p is equal to %c\n", *(char *)last->content);
// 	printf("content on the last p is equal to %c\n", *(char *)begin->next->next->next->content);
// 	return (0);
// }