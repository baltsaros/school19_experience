/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:33:28 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/13 09:33:30 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 65) || (str[i] > 90))
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

    str = "1AESZ";
    ft_str_is_uppercase(str);
	ret = ft_str_is_uppercase(str);
	printf("return is %d\n", ret);
	return (0);
}
*/
