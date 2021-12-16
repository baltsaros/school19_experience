#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (NULL == begin_list)
		return (NULL);
	if (nbr == 0)
		return (begin_list);
	else
		ft_list_at(begin_list->next, nbr - 1);
}

int		main(void)
{
	
}
