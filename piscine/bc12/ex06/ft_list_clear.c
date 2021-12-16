#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

// not finished

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	if (begin_list->next != 0)
		ft_list_clear(begin_list->next, free_fct);
	else
	{
		(*free_fct)(begin_list->data);
		free(begin_list);
	}
}

void	ft_free_fct(void *data)
{
	printf("data, that is equal to %d, was freed\n", *((int *)data));
	free(data);
}

int		main(void)
{
	int		*data;
	t_list	*elem;
	
	data = (int *)malloc(sizeof(int) * 3);
	data[0] = 11;
	data[1] = 22;
	data[2] = 33;
	elem = ft_create_elem((void *)&data[0]);
	// elem->next = ft_create_elem((void *)&data[1]);
	// elem->next->next = ft_create_elem((void *)&data[2]);
	ft_list_clear(elem, &ft_free_fct);
	return (0);
}
