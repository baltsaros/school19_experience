#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	if (!(elem = (t_list *)malloc(sizeof(*elem))))
		return (NULL);
	elem->data = data;
	elem->next = 0;
	return (elem);
}

int		main(void)
{
	int		data;
	t_list	*elem;

	data = 19;
	elem = ft_create_elem((void *)&data);
	printf("next elem is '%p'\n", (void *)elem->next);
	printf("data elem is '%d'\n", *((int *)elem->data));
	return (0);
}
