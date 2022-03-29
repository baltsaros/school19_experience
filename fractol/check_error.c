/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:34:33 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/29 14:35:29 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(void)
{
	printf("Invalid parameter(s)!\n");
	printf("The porgram should be executed in the following way:\n");
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

void	check_win(void *win)
{
	if (!win)
	{
		perror("Window is borken!\n");
		free(win);
		exit(EXIT_FAILURE);
	}
}
