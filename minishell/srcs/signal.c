/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltsaros <baltsaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:35:16 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/05/31 12:58:17 by baltsaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int						g_status;

/*static void	process(int sign_num)
{
	if (sign_num == SIGQUIT)
	{
		g_status = 128 + sign_num;
	}
	else if (sign_num == SIGINT)
	{
		ft_putstr_fd("\nyo >", 1);
		g_status = 128 + sign_num;
	}
}*/

void		sigint_handler(int sign_num)
{
	if (sign_num == SIGINT)
	{
		ft_putstr_fd("\nyo >", 1);
		g_status = 1;
	}
	else if (sign_num == SIGQUIT)
	{
			g_status = 128 + sign_num;
	}
}