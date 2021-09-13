/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:15:11 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/13 09:15:13 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 65) || (str[i] > 122))
		{
			return (0);
		}
		if ((str[i] <= 90 ) || (str[i] >= 97))
		{
			++i;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

/*
#include <stdio.h>
int	main()
{
	char    *str;
	int		ret;

	str = "tEst";
	ft_str_is_alpha(str);
	ret = ft_str_is_alpha(str);
	printf("return is %d\n", ret);
	return (0);
}
*/
