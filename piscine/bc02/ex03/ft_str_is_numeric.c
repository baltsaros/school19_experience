/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:24:54 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/13 09:24:56 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_numeric(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 48) || (str[i] > 57))
		{
			return (0);
		}
		++i;
	}
	return (1);
}

/*
#include <stdio.h>
int	main()
{
	char	*str;
	int		ret;

	str = "1234";
	ft_str_is_numeric(str);
	ret = ft_str_is_numeric(str);
	printf("return is %d\n", ret);
	return (0);
}
*/
