/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:29:58 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/12 14:32:36 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(count * size);
	if (NULL == ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		++i;
	}
	return (ptr);
}

// int	main(void)
// {
// 	int size = 8539;

// 	void * d1 = ft_calloc(size, sizeof(int));
// 	void * d2 = calloc(size, sizeof(int));
// 	if (memcmp(d1, d2, size * sizeof(int)))
// 		printf("fail\n");
// 	free(d1);
// 	free(d2);
// }
// int	main(void)
// {
// 	size_t	i;
// 	size_t	num;
// 	int		*ptr;

// 	i = 0;
// 	num = 8539;
// 	ptr = ft_calloc(num, sizeof(num));
// 	while (i < num)
// 	{
// 		write(1, &ptr[i], 1);
// 		write(1, "\n", 1);
// 		++i;
// 	}
// 	free(ptr);
// 	return (0);
// }