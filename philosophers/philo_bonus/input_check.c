/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:31 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/20 10:57:18 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_input	input_check(int argc, char *argv[])
{
	t_input	t_in;

	t_in.error = 0;
	if (argc != 5 && argc != 6)
	{
		t_in.error = -1;
		return (t_in);
	}
	t_in.n = ft_atoi(argv[1], &t_in.error);
	t_in.die = ft_atoi(argv[2], &t_in.error);
	t_in.eat = ft_atoi(argv[3], &t_in.error);
	t_in.sleep = ft_atoi(argv[4], &t_in.error);
	if (t_in.n == 0 || t_in.die == 0)
		t_in.error = -1;
	if (argv[5])
		t_in.each = ft_atoi(argv[5], &t_in.error);
	else
		t_in.each = -1;
	return (t_in);
}
