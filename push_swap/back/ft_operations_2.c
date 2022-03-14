#include "push_swap.h"

void	ra(t_data *data)
{
	ft_rotate_node(&(data->a));
}

void	rb(t_data *data)
{
	ft_rotate_node(&(data->b));
}

void	rr(t_data *data)
{
	ft_rotate_node(&(data->a));
	ft_rotate_node(&(data->b));
}
