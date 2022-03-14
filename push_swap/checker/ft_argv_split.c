/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:19:19 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/14 17:16:21 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_check_char(char *argv)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			space = 1;
		++i;
	}
	if (space)
		return (1);
	else
	{
		write(2, "Invalid delimeter\n", 18);
		exit(EXIT_FAILURE);
	}
}

static t_node	*input_check_spl(int length, char *split[])
{
	int		i;
	int		error;
	int		*ar;
	int		*ar_s;
	t_node	*stack_a;

	ar = malloc(sizeof(int) * (length));
	alloc_check_small(ar);
	i = 0;
	error = 0;
	while (split[i])
	{
		ar[i] = ft_atoi(split[i], &error);
		++i;
	}
	check_duplicate(ar, length, &error);
	check_error(ar, split, error);
	check_sort(ar, length);
	ar_s = ft_sort_array(ar, length);
	i = 0;
	stack_a = ft_init_stack(ar, ar_s, length);
	return (stack_a);
}

t_node	*ft_argv_split(char *argv)
{
	int		len;
	char	**split;
	t_node	*stack_a;

	ft_check_char(argv);
	split = ft_split(argv, ' ');
	alloc_check(split);
	len = 0;
	while (split[len])
		++len;
	stack_a = input_check_spl(len, split);
	free(split);
	return (stack_a);
}
