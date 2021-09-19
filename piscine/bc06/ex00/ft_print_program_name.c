/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:58:38 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/18 14:58:39 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
	write(1, "\n", 1);
}

/*
int		main(int argc, char **argv)
{
	(void)argc;
	ft_putstr(argv[0]);
	return (0);
}
*/