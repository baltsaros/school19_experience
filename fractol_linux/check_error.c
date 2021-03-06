/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltsaros <baltsaros@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:34:33 by abuzdin           #+#    #+#             */
/*   Updated: 2022/06/13 20:40:18 by baltsaros        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		exit(EXIT_FAILURE);
	}
}

void	check_win(t_data *data)
{
	if (!data->win)
	{
		perror("Window is borken!\n");
		mlx_destroy_image(data->mlx, data->img.mlx_img);
		exit(EXIT_FAILURE);
	}
}
