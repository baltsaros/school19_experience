/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:29:51 by abuzdin           #+#    #+#             */
/*   Updated: 2022/03/15 12:11:13 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	int				ix;
	int				nb;
	int				flag;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_data
{
	t_node	*a;
	t_node	*b;
	int		len_a;
	int		len_b;
}	t_data;

int		ft_atoi(const char *str, int *error);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		get_next_line(char **line);
void	alloc_check(char **str);
void	alloc_check_small(void *str);
void	alloc_check_node(t_node *new, t_node **node);
void	error_msg(void);
void	ft_exit(t_data *data, int code);
void	ft_swap(int *a, int *b);
void	ft_free(char *str[]);
t_node	*ft_free_node(t_node *node);
int		*ft_array_dup(int *old, int *new, int length);
void	check_duplicate(int *array, int length, int *error);
void	check_sort(int *array, int length);
void	check_error(int *array, char **split, int error);
void	check_error_array(int *array, int error);
void	ft_push_node(t_node **from, t_node **to);
void	ft_swap_node(t_node **node);
void	ft_rotate_node(t_node **node);
void	ft_reverse_node(t_node **node);
int		ft_sorted_node(t_node *stack, int len);
t_node	*ft_node_new(int index, int number);
void	ft_node_back(t_node **node, t_node *new);
t_node	*ft_node_del(t_node *node);
void	ft_node_print(t_node *node);
int		ft_node_size(t_node *node);
int		*ft_sort_array(int *array, int length);
void	ft_fill_stack(int i, int j, int *array, t_node **stack);
t_node	*ft_init_stack(int *ar, int *ar_s, int length);
t_node	*ft_argv_split(char *argv);
t_node	*input_check(int argc, char *argv[]);

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

#endif