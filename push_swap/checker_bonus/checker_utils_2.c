/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:30:53 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/15 12:25:12 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		write(1, "OK\n", 3);
		exit(EXIT_SUCCESS);
	}
}
