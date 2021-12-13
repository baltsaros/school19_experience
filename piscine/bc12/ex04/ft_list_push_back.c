#include <stdio.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list == 0)
		*begin_list = ft_create_elem(data);
	else
		ft_list_push_back(&((*begin_list)->next), data);
}

int		main(void)
{
	int		data;
	int		data2;
	int		data3;
	t_list	*elem;

	data = 11;
	data2 = 22;
	data3 = 33;
	elem = ft_create_elem((void *)&data);
	// elem->next = ft_create_elem((void *)&data2);
	ft_list_push_back(&elem, &data);
	ft_list_push_back(&elem, &data2);
	ft_list_push_back(&elem, &data3);
	printf("elem page1 is %d\n", *(int *)elem->data);
	printf("elem page2 is %d\n", *(int *)elem->next->data);
	printf("elem page3 is %d\n", *(int *)elem->next->next->data);
	printf("elem page3 is %d\n", *(int *)elem->next->next->next->data);
	return (0);
}