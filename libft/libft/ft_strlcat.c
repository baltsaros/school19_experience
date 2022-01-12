/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:33:36 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/12 09:38:25 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	remain;

	remain = size;
	while (*dst && remain > 0)
	{
		++dst;
		--remain;
	}
	len_d = size - remain;
	len_s = 0;
	while (src[len_s])
		++len_s;
	if (remain == 0)
		return (len_d + len_s);
	while (*src && remain > 1)
	{
		*dst = *src;
		++dst;
		++src;
		--remain;
	}
	*dst = '\0';
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
// 	memset(dest, 'r', 6);
// 	memset(dest2, 0, 15);
// 	memset(dest2, 'r', 6);
// 	dest[11] = 'a';
// 	dest2[11] = 'a';
// 	ret = ft_strlcat(dest, "lorem", 15);
// 	ret2 = strlcat(dest2, "lorem", 15);
// 	printf("FT: dest is '%s', ret is %ld\n", dest, ret);
// 	printf("OR: dest is '%s', ret is %ld\n", dest2, ret2);
// 	write(1, "\n", 1);
// 	write(1, dest, 15);
// 	write(1, "\n", 1);
// 	write(1, dest2, 15);
// 	write(1, "\n", 1);
// 	return (0);
// }