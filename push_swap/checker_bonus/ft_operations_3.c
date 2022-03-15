/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:20:33 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/15 12:38:14 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_data *data)
{
	ft_reverse_node(&(data->a));
}

void	rrb(t_data *data)
{
	ft_reverse_node(&(data->b));
}

void	rrr(t_data *data)
{
	ft_reverse_node(&(data->a));
	ft_reverse_node(&(data->b));
}
