/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:38:20 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/05/23 17:24:42 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	check_builtin(t_node args)
// {
// 	if (args.type == WORD)
// 	{
// 		if (!ft_strncmp(args.value, "echo", 4))
// 			return(BI_ECHO);
// 		if (!ft_strncmp(args.value, "-n", 2))
// 			return(BI_ECHON);
// 		if (!ft_strncmp(args.value, "cd", 2))
// 			return(BI_CD);
// 		if (!ft_strncmp(args.value, "pwd", 3))
// 			return(BI_PWD);
// 		if (!ft_strncmp(args.value, "export", 6))
// 			return(BI_EXPORT);
// 		if (!ft_strncmp(args.value, "unset", 5))
// 			return(BI_UNSET);
// 		if (!ft_strncmp(args.value, "env", 3))
// 			return(BI_ENV);
// 		if (!ft_strncmp(args.value, "exit", 4))
// 			return(BI_EXIT);
// 		else
// 			return(WORD);
// 	}
// 	return (0);
// }

// t_env_var	*check_assignment(t_node args)
// {
// 	char		*equal_place;
// 	t_env_var	*env_var;
// 	int			i;

// 	i = 0;
// 	if (args.value[0] == '?')
// 	{
// 		printf("\n Error: %s command not found", args.value);
// 		g_status = 127;
// 	}
// 	if (equal_place == ft_strchr(args.value, '='))
// 	{
// 		while (args.value[i] != '=')
// 		{
// 			env_var->name[i] = args.value[i];
// 			i++; 
// 		}
// 		env_var->name[i] = 0;
// 		i = 0;
// 		while (++equal_place)
// 		{
// 			env_var->value[i] = *equal_place;
// 			i++;
// 		}
// 		env_var->value[i] = 0;
// 		return (env_var);
// 	}
// 	else 
// 		return (NULL);
// }

// int	check_if_assigned(t_node args, t_env_var env_var)
// {
// 	char	*dollar_place;
// 	char	*var_check;
// 	int		i;

// 	if (dollar_place == ft_strchr(args.value, '$'))
// 	{
// 		while (args.value[i] != '$')
// 			i++;
// 		while (args.value[i])
// 		{
// 			var_check[i] = args.value[i];
// 			i++;
// 		}
// 		var_check[i] = 0;
// 		if (!ft_strncmp(env_var.name, var_check, ft_strlen(env_var.name)))
// 			return(1);
// 	}
// 	return (0);
// }

