/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:36:13 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/22 10:36:17 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		j;
	int		length;
	char	*copy;

	length = ft_strlen(str);
	copy = (char *)malloc(sizeof(copy) * (length + 1));
	if (NULL == copy)
		return (NULL);
	j = 0;
	while (str[j])
	{
		copy[j] = str[j];
		++j;
	}
	copy[j] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*stocks;
	int				i;

	stocks = malloc(sizeof(*stocks) * (ac + 1));
	if (NULL == stocks)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stocks[i].size = ft_strlen(av[i]);
		stocks[i].str = av[i];
		stocks[i].copy = ft_strdup(av[i]);
		++i;
	}
	stocks[i].str = 0;
	return (stocks);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int		k;
	struct s_stock_str	*results;

	results = ft_strs_to_tab(argc, argv);
	k = 0;
	while (k < argc)
	{
		printf("argc - %d\n", k);
		printf("size %d | str%d %s | copy %s\n", results[k].size, k, 
			results[k].str, results[k].copy);
		++k;
	}
	return (0);
}
*/