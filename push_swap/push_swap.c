#include "push_swap.h"

t_data	*ft_init_data(t_node *stack)
{
	t_data	*data;

	data->stack_a = stack;
	data->stack_b = NULL;
	data->len_a = ft_node_size(stack);
	data->len_b = 0;
	data->min = 1;
	data->med = data->len_a / 2;
	return (data);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_data	*data;

	if (argc == 1)
		return (0);
	stack_a = input_check(argc, argv);
	data = ft_init_data(stack_a);
	ft_node_print(data->stack_a);
	printf("len_a is %d\n", data->len_a);
	ft_node_print(data->stack_b);
	printf("len_b is %d\n", data->len_b);
	printf("min is %d\n", data->min);
	printf("med is %d\n", data->med);
	return (0);
}