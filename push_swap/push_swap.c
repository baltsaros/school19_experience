#include "push_swap.h"

t_data	*ft_init_data(t_node *stack)
{
	t_data	*data;

	data->a = stack;
	data->b = NULL;
	data->len_a = ft_node_size(stack);
	data->len_b = 0;
	data->min = 1;
	data->med = ft_find_med(data->a);
	data->iter = 1;
	data->rb = 0;
	data->score_a = 0;
	data->score_b = 0;
	return (data);
}

void	ft_sort(t_data *data)
{
	if (data->len_a < 7)
		ft_sort_small(data);
	else
		ft_sort_big(data);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_data	*data;
	int		*array;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		stack_a = ft_argv_split(argv[1]);
	else
		stack_a = input_check(argc, argv);
	data = ft_init_data(stack_a);
	ft_sort(data);
	// printf("med is %d\n", data->med);
	return (0);
}
