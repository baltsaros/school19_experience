/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:07:07 by abuzdin           #+#    #+#             */
/*   Updated: 2022/01/27 12:17:10 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_par
{
	int	zero;
	int	minus;
	int	dot;
	int	space;
	int	plus;
	int	sharp;
	int	width;
	int	type;
}	t_par;

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *r);
void	ft_putstr(char *str, int *r);
void	ft_output_char(t_par *params, char c, int *r);
void	ft_output_nbr(t_par *params, int nbr, int *r);
void	ft_output_str(t_par *params, char *str, int *r);
void	ft_output_nbr_un(t_par *params, unsigned int nbr, int *r);
void	ft_output_hex(t_par *params, unsigned int nbr, int *r);
void	ft_output_hex_x(t_par *params, unsigned int nbr, int *r);
void	ft_output_ptr(t_par *params, unsigned long long nbr, int *r);

#endif