/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:35:15 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/14 09:35:16 by abuzdin          ###   ########.fr       */
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
	dest[j] = '\0';
	return (dest);
}

/*
#include <stdio.h>
int		main()
{
	char	dest[] = "destination";
	char	src[] = "so";
	
	printf("dest before %s\n", dest);
	ft_strcpy(dest, src);
	printf("src %s\n", src);
	printf("dest after %s\n", dest);
	return (0);
}
*/
