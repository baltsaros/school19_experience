/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:34:10 by abuzdin           #+#    #+#             */
/*   Updated: 2021/10/19 13:00:37 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t num, size_t size);
int		ft_isalnum(int ch);
int		ft_isalpha(int ch);
int		ft_isdigit(int ch);
int		ft_isprint(int ch);
void	*ft_memchr(const void *buffer, int ch, size_t n);
int		ft_memcmp(const void *buffer1, const void *buffer2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *dest, int ch, size_t n);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char 	*ft_strnstr(const char *big, const char *little, size_t n);
char	*ft_strrchr(const char *str, int ch);
int		ft_tolower(int ch);
int		ft_toupper(int ch);
#endif