#include <stdio.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*elem;

	if (size == 0)
		return (0);
	elem = ft_create_elem((void *)strs[size - 1]);
	elem->next = ft_list_push_strs(size - 1, strs);
	return (elem);
}

int		main(int argc, char **argv)
{
	t_list	*elem;
	int		i;

	elem = ft_list_push_strs(argc, argv);
	i = 0;
	while (elem)
	{
		printf("elem[%d] is '%s'\n", i, (char *)elem->data);
		++i;
		elem = elem->next;
	}
	return (0);
}
