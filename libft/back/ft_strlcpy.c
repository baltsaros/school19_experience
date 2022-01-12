/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:33:40 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 14:10:08 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;

	len_s = 0;
	while (src[len_s])
		++len_s;
	if (size == 0)
		return (len_s);
	i = 0;
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (len_s);
}

// int	main(void)
// {
// 	char	*dest;
// 	char	*dest2;
// 	size_t	ret;
// 	size_t	ret2;

// 	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
// 		return (0);
// 	if (!(dest2 = (char *)malloc(sizeof(*dest) * 15)))
// 		return (0);
// 	memset(dest, 0, 15);
// 	memset(dest, 'r', 6);
// 	memset(dest2, 0, 15);
// 	memset(dest2, 'r', 6);
// 	ret = ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
// 	ret2 = strlcpy(dest2, "lorem ipsum dolor sit amet", 0);
// 	printf("FT: dest is '%s', ret is %ld\n", dest, ret);
// 	printf("OR: dest is '%s', ret is %ld\n", dest2, ret2);
// 	write(1, "\n", 1);
// 	write(1, dest, 15);
// 	write(1, "\n", 1);
// 	write(1, dest2, 15);
// 	return (0);
// }