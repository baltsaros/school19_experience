#include "push_swap.h"

void	rra(t_data *data)
{
	ft_reverse_node(&(data->a));
}

void	rrb(t_data *data)
{
	ft_reverse_node(&(data->b));
}

void	rrr(t_data *data)
{
	ft_reverse_node(&(data->a));
	ft_reverse_node(&(data->b));
}
