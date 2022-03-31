/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:34:33 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/31 12:14:34 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_msg(void)
{
	printf("Invalid parameter(s)!\n");
	printf("The program should be executed in the following way:\n");
	printf("./fractol <fractal set> <color set> <constant set>\n");
	printf("<fractal set> values: Mandelbrot, Julia, Ship\n");
	printf("<color set> values: 1, 2, 3\n");
	printf("<constant set> is only used for Julia set. It can be: 1, 2, 3\n");
	printf("Please, try again\n");
	exit(EXIT_FAILURE);
}

void	check_mlx(void *mlx)
{
	if (!mlx)
	{
		perror("Mlx init error\n");
		free(mlx);
		exit(EXIT_FAILURE);
	}
}

void	check_win(t_data *data)
{
	if (!data->win)
	{
		perror("Window is borken!\n");
		free(data->mlx);
		free(data->win);
		exit(EXIT_FAILURE);
	}
}
