/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 09:33:40 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/10 09:33:41 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_s;

	size_s = 0;
	while (src[size_s])
		++size_s;
	i = 0;
	while (i < size && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (size_s);
}

// int	main(void)
// {
// 	char	dest[6];
// 	char	src[13] = "Hello world!";
// 	size_t	ret;

// 	ret = ft_strlcpy(dest, src, 5);
// 	// ret = strlcpy(dest, src, 10);
// 	printf("src is '%s', dest is '%s', ret is %ld\n", src, dest, ret);
// 	return (0);
// }