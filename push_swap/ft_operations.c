#include "push_swap.h"

void	sa(t_data *data)
{
	ft_swap_node(&(data->a));
	write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	ft_swap_node(&(data->b));
	write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	ft_swap_node(&(data->a));
	ft_swap_node(&(data->b));
	write(1, "ss\n", 3);
}

void	pa(t_data *data)
{
	ft_push_node(&(data->b), &(data->a));
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	ft_push_node(&(data->a), &(data->b));
	write(1, "pb\n", 3);
}

