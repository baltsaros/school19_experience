/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:20:33 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/14 16:24:18 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
