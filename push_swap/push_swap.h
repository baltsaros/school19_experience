#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

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
	t_node	*stack_a;
	t_node	*stack_b;
	int		len_a;
	int		len_b;
	int		min;
	int		med;
}	t_data;

void	alloc_check(char **str);
void	alloc_check_small(void *str);
void	alloc_check_node(t_node *new, t_node **node);
void	ft_free(char *str[]);
void	error_msg();
void	ft_swap(int *a, int *b);
int		*ft_array_dup(int *old, int *new, int length);
t_node	*ft_node_new(int index, int number);
void	ft_node_front(t_node **node, t_node *new);
void	ft_node_back(t_node **node, t_node *new);
t_node	*ft_node_del(t_node *node);
void	ft_node_print(t_node *node); // DELETE AFTER
int		ft_node_size(t_node *node);
t_node	*ft_switch_stack(t_node *one, t_node **two);
t_node	*ft_free_node(t_node *node);
t_node	*input_check(int argc, char *argv[]);
void	ft_push_node(t_node **from, t_node **to);
void	ft_swap_node(t_node **node);
void	ft_rotate_node(t_node **node);
void	ft_reverse_node(t_node **node);

#endif