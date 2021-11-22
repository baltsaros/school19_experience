#include <stdlib.h>
#include <stdio.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	if (!(elem = (t_list *)malloc(sizeof(*elem))))
		return (NULL);
	elem->data = data;
	elem->next = 0;
	return (elem);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	new_elem = ft_create_elem(data);
	new_elem->next = (*begin_list);
	*begin_list = new_elem;
}

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

int		main(void)
{
	int		data;
	int		data2;
	t_list	*elem;

	data = 19;
	data2 = 42;
	elem = ft_create_elem(&data);
	ft_list_push_front(&elem, &data2);
	printf("address of page2 is %p\n", (void *)elem->next);
	printf("data page1 is %d\n", *((int *)elem->data));
	printf("address of page 3 is %p\n", (void *)elem->next->next);
	printf("data page2 is %d\n", *(int *)elem->next->data);
	printf("t_list size is %d\n", ft_list_size(elem));
	return (0);
}
