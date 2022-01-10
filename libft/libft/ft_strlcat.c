/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:33:36 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 14:19:44 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_d = 0;
	while (dst[len_d])
		++len_d;
	len_s = 0;
	while (src[len_s])
		++len_s;
	if (size == 0)
		return (len_s);
	i = 0;
	while (src[i] && (len_d + i < size - 1))
	{
		dst[len_d + i] = src[i];
		++i;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}

// int	main(void)
// {
// 	char	*dest;
// 	char	*dest2;
// 	size_t	ret;
// 	size_t	ret2;

// 	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
// 		return (0);
// 	if (!(dest2 = (char *)malloc(sizeof(*dest2) * 15)))
// 		return (0);
// 	memset(dest, 0, 15);
// 	memset(dest, 'r', 14);
// 	memset(dest2, 0, 15);
// 	memset(dest2, 'r', 14);
// 	// dest[10] = 'a';
// 	// dest2[10] = 'a';
// 	ret = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
// 	ret2 = strlcat(dest2, "lorem ipsum dolor sit amet", 5);
// 	printf("FT: dest is '%s', ret is %ld\n", dest, ret);
// 	printf("OR: dest is '%s', ret is %ld\n", dest2, ret2);
// 	write(1, "\n", 1);
// 	write(1, dest, 15);
// 	write(1, "\n", 1);
// 	write(1, dest2, 15);
// 	return (0);
// }