/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:43:18 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/13 09:43:20 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65) && (str[i] <= 90))
		{
			str[i] = str[i] + 32;
		}
		++i;
	}
	return (str);
}

/*
#include <stdio.h>
int        main()
{
    char    str[] = "1AESZ";

    printf("first %s\n", str);
    ft_strlowcase(str);
    printf("third %s\n", str);
    return (0);
}
*/