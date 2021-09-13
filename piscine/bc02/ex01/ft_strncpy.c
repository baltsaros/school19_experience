/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:57:13 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/13 08:57:15 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		d;
	unsigned int		j;

	d = ft_strlen(dest);
	j = 0;
	while (j != d)
	{
		if (j <= n)
		{
			dest[j] = src[j];
			j++;
		}
		else
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (dest);
}

/*
#include <stdio.h>
int		main()
{
	char	dest[] = "destination";
	char	src[] = "source";
	unsigned int	n;

	n = ft_strlen(src);
	printf("strlen SRC is %d\n", n);
	printf("sizeofsrc is %lu\n", sizeof(src));
	printf("dest is %s\n", dest);
	printf("sizeof DEST is %lu\n", sizeof(dest));
	ft_strncpy(dest, src, n);
	printf("dest2 is %s\n", dest);
	printf("sizeof2 DEST is %lu\n", sizeof(dest));
}
*/
