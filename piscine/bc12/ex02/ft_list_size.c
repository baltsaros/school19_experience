#include <stdio.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		size;

	size = 0;
	while (begin_list)
	{
		++size;
		begin_list = begin_list->next;
	}
	return (size);
}

int	main(void)
{
	int		data;
	int		data2;
	t_list	*elem;

	data = 19;
	data2 = 20;
	elem = ft_create_elem((void *)&data);
	elem->next = ft_create_elem((void *)&data2);
	elem->next->next = ft_create_elem((void *)&data2);
	printf("t_list size is %d\n", ft_list_size(elem));
	return (0);
}
