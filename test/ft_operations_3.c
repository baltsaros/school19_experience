/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:35:08 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/14 17:35:09 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	ft_reverse_node(&(data->a));
	write(1, "rra\n", 4);
}

void	rrb(t_data *data)
{
	ft_reverse_node(&(data->b));
	write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	ft_reverse_node(&(data->a));
	ft_reverse_node(&(data->b));
	write(1, "rrr\n", 4);
}
