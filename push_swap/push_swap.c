#include "push_swap.h"

int	ft_find_med(t_node *stack)
{
	int		i;
	int		sum;
	int		len;
	t_node *tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	len = ft_node_size(tmp);
	sum = 0;
	sum = i;
	while (i < len)
	{
		++i;
		sum += tmp->ix;
		printf("sum[%d] is %d\n", i, sum);
		tmp = tmp->next;
	}
	return (sum / 2);
}

t_data	*ft_init_data(t_node *stack)
{
	t_data	*data;

	data->a = stack;
	data->b = NULL;
	data->len_a = ft_node_size(stack);
	data->len_b = 0;
	data->min = 1;
	data->med = ft_find_med(data->a);
	return (data);
}

// void	ft_sort(t_data *data)
// {
// 	while (1)
// 	{
// 		if (data->a->ix > data->med)
// 		{
// 			pb;
// 			--data->len_a;
// 			++data->len_b;
// 		}
// 		if (data->a->ix <= data->med)
// 			ra;
// 	}
// }

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_data	*data;
	int		*array;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		stack_a = ft_argv_split(argc, argv[1]);
	else
		stack_a = input_check(argc, argv);
	data = ft_init_data(stack_a);
	printf("med is %d\n", data->med);
	return (0);
}
