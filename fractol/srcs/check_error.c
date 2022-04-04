/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:34:33 by abuzdin           #+#    #+#             */
/*   Updated: 2022/04/04 15:31:05 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_msg(void)
{
	ft_printf("Invalid parameter(s)!\n");
	ft_printf("The program should be executed in the following way:\n");
	ft_printf("./fractol <fractal set> <color set> <constant set>\n");
	ft_printf("<fractal set> values: Mandelbrot, Julia, Ship\n");
	ft_printf("<color set> values: 1, 2, 3\n");
	ft_printf("<constant set> is only used for Julia set. It can be: 1, 2, 3\n");
	ft_printf("Please, try again\n");
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
