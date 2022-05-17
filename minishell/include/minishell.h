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
# include <libft.h>
// # include "libft/libft.h"

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

typedef struct s_env
{
	char			*type;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_input
{
	int		argc;
	char	**argv;
	char	**envp;
	t_env	*envp_n;
	t_node	*args;
	char	*buf;
	int		status;
}	t_input;


// allocation check
void	alloc_check(char **str);
void	alloc_check_small(void *str);
void	alloc_check_token(t_node *new, t_node **node);
void	alloc_check_envp(t_env *new, t_env **node);

// tokens
t_node	*ft_token_new(int type, char *value);
void	ft_token_back(t_node **node, t_node *new);
t_node	*ft_token_del(t_node *node);
void	ft_token_print(t_node *node);
int		ft_token_size(t_node *node);

// envp tokens
t_env	*ft_envp_new(char *type, char *value);
void	ft_envp_back(t_env **node, t_env *new);
t_env	*ft_envp_del(t_env *node);
void	ft_envp_print(t_env *node);
int		ft_envp_size(t_env *node);

// free
void	ft_free(char *str[]);
t_node	*ft_free_token(t_node *node);
t_env	*ft_free_envp(t_env *node);

// utils
char	*ft_strndup(char const *str, size_t size);
char	**ft_split_op(char const *s, char c);

// minishell

#endif