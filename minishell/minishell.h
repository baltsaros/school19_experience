#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>

// # define SEPAR 1
// # define WORD 2
// # define QUOTE 3
// # define QUOTE_D 4
// # define REDIR_OUT 5
// # define REDIR_IN 6
// # define REDIR_AP 7
// # define REDIR_HD 8
// # define PIPE 9

enum tokens
{
	SEPAR		= 1,
	WORD		= 2,
	QUOTE		= 3,
	QUOTE_D		= 4,
	REDIR_OUT	= 5,
	REDIR_IN	= 6,
	REDIR_AP	= 7,
	REDIR_HD	= 8,
	PIPE		= 9
};

typedef struct s_node
{
	int				type;
	char			*value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_input
{
	int		argc;
	char	**argv;
	char	**envp;
	t_node	envp_n;
	char	*buf;
}	t_input;


// allocation check
void	alloc_check(char **str);
void	alloc_check_small(void *str);
void	alloc_check_node(t_node *new, t_node **node);

// nodes
t_node	*ft_node_new(int type, char *value);
void	ft_node_back(t_node **node, t_node *new);
t_node	*ft_node_del(t_node *node);
void	ft_node_print(t_node *node);
int		ft_node_size(t_node *node);


#endif