/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:10:07 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/19 11:07:24 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(int *array, int length, int *error)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length && array[i] != array[j])
			++j;
		if (j < length && array[i] == array[j])
			*error = 1;
		++i;
	}
}

void	check_sort(int *array, int length)
{
	int	i;

	i = 0;
	while (i + 1 < length && array[i] < array[i + 1])
		++i;
	if (i + 1 == length)
	{
		free(array);
		exit(EXIT_SUCCESS);
	}
}

void	check_sort_split(int *array, int length, char **split)
{
	int	i;

	i = 0;
	while (i + 1 < length && array[i] < array[i + 1])
		++i;
	if (i + 1 == length)
	{
		free(array);
		ft_free(split);
		exit(EXIT_SUCCESS);
	}
}

void	check_error(int *array, char **split, int error)
{
	if (error)
	{
		free(array);
		ft_free(split);
		error_msg();
	}
}

void	check_error_array(int *array, int error)
{
	if (error)
	{
		free(array);
		error_msg();
	}
}
