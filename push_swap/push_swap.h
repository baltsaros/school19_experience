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

typedef struct s_stacks
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		min;
	int		med;
	int		len_a;
	int		len_b;
}	t_stacks;

void	alloc_check(char **str);
void	alloc_check_small(void *str);
void	ft_free(char *str[]);
void	error_msg();

#endif