/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:57:29 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/14 17:10:26 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_init_data(t_data *data, t_node *stack)
{
	data->a = stack;
	data->b = NULL;
	data->len_a = ft_node_size(stack);
	data->len_b = 0;
}

void	ft_check_operation(char *op, t_data *data)
{
	if (ft_strncmp(op, "sa", 3) == 0)
		sa(data);
	else if (ft_strncmp(op, "sb", 3) == 0)
		sb(data);
	else if (ft_strncmp(op, "ss", 3) == 0)
		ss(data);
	else if (ft_strncmp(op, "pa", 3) == 0)
		pa(data);
	else if (ft_strncmp(op, "pb", 3) == 0)
		pb(data);
	else if (ft_strncmp(op, "ra", 3) == 0)
		ra(data);
	else if (ft_strncmp(op, "rb", 3) == 0)
		rb(data);
	else if (ft_strncmp(op, "rr", 3) == 0)
		rr(data);
	else if (ft_strncmp(op, "rra", 4) == 0)
		rra(data);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		rrb(data);
	else if (ft_strncmp(op, "rrr", 4) == 0)
		rrr(data);
	else
		error_msg();
}

void	ft_checker_sort(t_data data)
{
	if (ft_sorted_node(data.a, data.len_a) && !data.b)
		write(1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_data	data;
	char	*line;
	int		ret;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		stack_a = ft_argv_split(argv[1]);
	else
		stack_a = input_check(argc, argv);
	ft_init_data(&data, stack_a);
	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		ret = get_next_line(&line);
		if (ret <= 0 || !line)
			break ;
		ft_check_operation(line, &data);
		free(line);
	}
	ft_checker_sort(data);
	return (0);
}
