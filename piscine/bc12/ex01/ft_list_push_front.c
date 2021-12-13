#include <stdio.h>
#include "ft_list.h"
void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	new_elem = ft_create_elem(data);
	new_elem->next = (*begin_list);
	*begin_list = new_elem;
}

int		main(void)
{
	int		data;
	int		data2;
	t_list	*elem;

	data = 19;
	data2 = 42;
	elem = ft_create_elem((void *)&data);
	ft_list_push_front(&elem, (void *)&data2);
	printf("address of page2 is %p\n", (void *)elem->next);
	printf("data page1 is %d\n", *((int *)elem->data));
	printf("address of page 3 is %p\n", (void *)elem->next->next);
	printf("data page2 is %d\n", *(int *)elem->next->data);
	return (0);
}
