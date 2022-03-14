/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:20:27 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/14 16:24:13 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	--data->len_b;
	++data->len_a;
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	ft_push_node(&(data->a), &(data->b));
	++data->len_b;
	--data->len_a;
	write(1, "pb\n", 3);
}
