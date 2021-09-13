/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:37:15 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/13 09:37:17 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 32) || (str[i] > 126))
		{
			return (0);
		}
		++i;
	}
	return (1);
}

/*
#include <stdio.h>
int		main()
{
	char	*str;
	int		ret;

	str = "\a{aesz";
	ft_str_is_printable(str);
	ret = ft_str_is_printable(str);
	printf("return is %d\n", ret);
	return (0);
}
*/