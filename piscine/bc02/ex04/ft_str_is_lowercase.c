/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:30:19 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/13 09:30:21 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 97) || (str[i] > 122))
		{
			return (0);
		}
		++i;
	}
	return (1);
}

/*
#include <stdio.h>
int        main()
{
    char    *str;
	int		ret;

    str = "aesz";
    ft_str_is_lowercase(str);
	ret = ft_str_is_lowercase(str);
	printf("return is %d\n", ret);
	return (0);
}
*/