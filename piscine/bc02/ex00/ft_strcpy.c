/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:48:42 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/13 08:48:44 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcpy(char *dest, char *src)
{
	int		j;

	j = 0;
	while (src[j] != '\0')
	{
		dest[j] = src[j];
		++j;
	}
	return (dest);
}

/*
#include <stdio.h>
int		main()
{
	char	dest[] = "destin";
	char	src[] = "source";
	ft_strcpy(dest, src);
	printf("source %s\n", src);
	printf("destination %s\n", dest);
	return (0);
}
*/
