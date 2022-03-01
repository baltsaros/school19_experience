/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:06:42 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/01 11:13:34 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		error_check(int input, char *str, int n);
void	ft_free(char *str[]);
void	*ft_calloc(size_t count, size_t size);
char	**get_address(char *cmd[], char *envp[]);
char	*access_check(char *cmd[], char *envp[]);
int		get_next_line(char **line);
void	ft_execve(char *argv, char *envp[]);
int		ft_open(char *file, int par);

#endif