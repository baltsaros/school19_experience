/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:20:18 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/15 12:38:09 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_data *data)
{
	ft_rotate_node(&(data->a));
}

void	rb(t_data *data)
{
	ft_rotate_node(&(data->b));
}

void	rr(t_data *data)
{
	ft_rotate_node(&(data->a));
	ft_rotate_node(&(data->b));
}
