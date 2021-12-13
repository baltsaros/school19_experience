#include <stdio.h>
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while(begin_list->next)
		begin_list = begin_list->next;
	return(begin_list);
}

int		main(void)
{
	int		data;
	int		data2;
	int		data3;
	t_list	*elem;
	t_list	*last;

	data = 11;
	data2 = 22;
	data3 = 33;
	elem = ft_create_elem((void *)&data);
	elem->next = ft_create_elem((void *)&data2);
	elem->next->next = ft_create_elem((void *)&data3);
	last = ft_list_last(elem);
	printf("last elem is %d\n", *(int *)last->data);
	return (0);
}
