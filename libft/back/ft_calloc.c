/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:29:58 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 12:03:18 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(count * size);
	if (NULL == ptr)
		return (NULL);
	while (i < count)
	{
		ptr[i] = 0;
		++i;
	}
	return (ptr);
}

// int	main(void)
// {
// 	size_t	i;
// 	size_t	num;
// 	int		*ptr;

// 	i = 0;
// 	num = 5;
// 	ptr = ft_calloc(num, sizeof(int));
// 	while (i < num)
// 	{
// 		write(1, &ptr[i], 1);
// 		write(1, "\n", 1);
// 		++i;
// 	}
// 	free(ptr);
// 	return (0);
// }