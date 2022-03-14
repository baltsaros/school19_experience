#include "push_swap.h"

void	ra(t_data *data)
{
	ft_rotate_node(&(data->a));
	write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	ft_rotate_node(&(data->b));
	write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	ft_rotate_node(&(data->a));
	ft_rotate_node(&(data->b));
	write(1, "rr\n", 3);
}
