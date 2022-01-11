/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:33:36 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/11 15:04:27 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dest;
	char	*source;
	size_t	dst_length;
	size_t	remaing;

	dest = dst;
	source = (char *)src;
	remaing = dstsize;
	while (remaing-- != 0 && *dest != '\0')
		dest++;
	dst_length = dest - dst;
	remaing = dstsize - dst_length;
	if (remaing == 0)
		return (dst_length + ft_strlen(source));
	while (*source != '\0')
	{
		if (remaing > 1)
		{
			*dest++ = *source;
			remaing--;
		}
		source++;
	}
	*dest = '\0';
	return (dst_length + (source - src));
}

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
	while (src && remain > 1)
	{
		*dst = *src;
		++dst;
		++src;
		--remain;
	}
	*dst = '\0';
	return (len_d + len_s);
}

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	len_d;
// 	size_t	len_s;
// 	size_t	len_copy;
// 	size_t	free_size;

// 	len_s = 0;
// 	free_size = size;
// 	while (src[len_s])
// 		++len_s;
// 	while (*dst && free_size > 0)
// 	{
// 		++dst;
// 		--free_size;
// 	}
// 	len_d = size - free_size;
// 	if (len_d < free_size)
// 	{
// 		len_copy = free_size - 1;
// 		if (len_s < len_copy)
// 			len_copy = len_s;
// 	}
// 	while (*src && size > 1)

// }

int	main(void)
{
	char	*dest;
	char	*dest2;
	size_t	ret;
	size_t	ret2;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	if (!(dest2 = (char *)malloc(sizeof(*dest2) * 15)))
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 10);
	memset(dest2, 0, 15);
	memset(dest2, 'r', 10);
	// dest[10] = 'a';
	// dest2[10] = 'a';
	ret = ft_strlcat(dest, "lorem ipsum dolor sit amet", 15);
	ret2 = strlcat(dest2, "lorem ipsum dolor sit amet", 15);
	printf("FT: dest is '%s', ret is %ld\n", dest, ret);
	printf("OR: dest is '%s', ret is %ld\n", dest2, ret2);
	write(1, "\n", 1);
	write(1, dest, 15);
	write(1, "\n", 1);
	write(1, dest2, 15);
	write(1, "\n", 1);
	return (0);
}