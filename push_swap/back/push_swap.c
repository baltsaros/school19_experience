/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:08:22 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/15 10:57:47 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_data(t_node *stack, t_data *data)
{
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
}

void	ft_sort_big(t_data *data)
{
	int	limit;

	while (data->len_a > 3)
	{
		data->med = ft_find_med(data->a);
		limit = ft_find_limit(data);
		while (limit > 0)
		{
			if (data->a->ix >= data->med)
				ra(data);
			else
			{
				data->a->flag = data->iter;
				pb(data);
				--limit;
			}
		}
		++data->iter;
	}
	ft_sort_three_a(data);
	ft_sort_big_b(data);
	ft_sort_three_b(data);
	ft_exit(data, 0);
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
	t_data	data;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		stack_a = ft_argv_split(argv[1]);
	else
		stack_a = input_check(argc, argv);
	ft_init_data(stack_a, &data);
	ft_sort(&data);
	return (0);
}
