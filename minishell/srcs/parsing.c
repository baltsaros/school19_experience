/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:44:46 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/05/23 17:56:48 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// interesting: if p1 | p2 -> p2 always gets excuted, even if 1 doesnt exist or is not comaptible -> exit never works with pipe
// p1 only gets excecuted if p2 exists
// check for pipes
// check for redirects
// assign priority


// t_node		*ft_assign_builtin(t_node *args)
// {
// 	t_node *head;

// 	head = args;
// 	while (head)
// 	{
// 		checkbuiltin(args);
// 		args = args->next;
// 	}
// 	return (args);
// }

// t_cell	*cell_init(void)
// {
// 	t_cell	*cell;
// 	cell->cmds = NULL;
// 	cell->next = NULL;
// 	cell->prev = NULL;
// 	cell->redir = 0;
// 	cell->tmp_in = stdin;
// 	cell->tmp_out = stdout;
// 	return (cell);
// }

// t_cell	*ft_create_cells(t_node *args)
// {
// 	t_cell	**cell_list;
// 	t_cell	*cell;
// 	t_node	*head;

// 	ft_assign_builtin(args);
// 	head = args;
// 	while (head)
// 	{
// 		while (head->type != PIPE && head)
// 		{
// 			cell = cell_init();
// 			ft_cell_add_cmd(cell, args);
// 			args = args->next;
// 		}
// 		ft_cell_back(&cell_list, cell);
// 		args = args->next;
// 	}
// 	return (cell_list);
// }

// void	ft_redirect(t_cell *cell_l)
// {
// 	while (cell_l->cmds)
// 	{
// 		if ((*cell_l).cmds.type == REDIR_OUT)
// 			(*cell_l).redir = REDIR_OUT;
// 		else if ((*cell_l).cmds.type == REDIR_IN)
// 			(*cell_l).redir = REDIR_IN;
// 		else if ((*cell_l).cmds.type == REDIR_AP)
// 			(*cell_l).redir = REDIR_OUT;
// 		else if ((*cell_l)->cmds.type == REDIR_HD)
// 			(*cell_l).redir = REDIR_OUT;
// 		else
// 			(*cell_l).redir = 0;
// 		cell_l = cell_l->next;
// 	}
// }

// void	*ft_finish_cells(t_cell *cell_l)
// {
// 	t_cell *head;

// 	head = cell_l;
// 	while (head)
// 	{
// 		fr_redirect(head);
// 		head = head->next;
// 	}
// }

/*t_cell_list	**ft_cell_list(t_node *args)
{
	t_cell_list	*cmd_ls;

	while (args)
	{
		cmd_ls->cell = ft_create_cells(args);
		cmd_ls = cmd_ls->next;
	}
}*/