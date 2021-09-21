/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 07:23:12 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/21 07:23:13 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		size;
	int		i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(sizeof(int) * size);
	if (NULL == *range)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		++min;
		++i;
	}
	return (i);
}

/*
#include <stdio.h>
int	main()
{
	int		*range;
	int		ret;

	ret = ft_ultimate_range(&range, 1, 6);
	printf("return is %d\n", ret);
	return (0);
}
*/