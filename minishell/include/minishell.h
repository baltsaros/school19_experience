#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
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
	DOLLAR		= 36,
	WORD		= 2,
	WORD_AST	= 3,
	QUOTE		= 39,
	QUOTE_D		= 34,
	REDIR_OUT	= 62,
	REDIR_IN	= 60,
	REDIR_AP	= 7,
	REDIR_HD	= 8,
	DELIM		= 9,
	PIPE		= 124,
	EQUAL		= 61,
	ASTER		= 42,
	AND			= 13,
	OR			= 14,
	BR_L		= 40,
	BR_R		= 41,
	AMPER		= 38,
	APOST		= 44,
	BACKSL		= 92
};

// enum builtins
// {
// 	BI_ECHO		= 10,
// 	BI_CD 		= 11,
// 	BI_PWD		= 12,
// 	BI_EXPORT	= 13,
// 	BI_UNSET	= 14,
// 	BI_ENV		= 15,
// 	BI_EXIT		= 16,
// 	BI_ECHON	= 17
// };

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

typedef	struct s_cell
{
	t_node			*cmds;
	int				redir;
	int				tmp_in;
	int				tmp_out;
	
	struct s_cell	*next;
	struct s_cell	*prev;
}	t_cell;

typedef struct s_cell_list
{
	struct s_cell		*cell;
	struct s_cell_list	*next;
	struct s_cell_list	*prev;
}	t_cell_list;

typedef struct s_input
{
	int				i;
	int				j;
	char			*tmp;
	char			*type;
	char			*value;
	t_env			*envp_tmp;
	t_node			*node_tmp;
	int				argc;
	int				in;
	int				out;
	char			**argv;
	char			**envp;
	t_env			*envp_n;
	t_node			*args;
	t_node			*wild;
	char			*buf;
	struct builtin	*builtins;
	int				status;
}	t_input;

struct builtin
{
	char	*name;
	int		(*func)(t_input *data);
};
typedef	struct s_env_var
{
	char	*name;
	char	*value;
}	t_env_var;

// global var

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
int		error_check(int input, char *str, int n);
char	*ft_strjoin_free(char *rest, char *buf);
char	*ft_charjoin_free(char *line, char b);

char	**get_address(char *cmd[], char *envp[]);
char	*access_check(char *cmd[], char *envp[]);
void	ft_execve(char *argv, char *envp[]);
int		ft_open(char *file, int par);

char	**ft_split_space(char const *s, char *charset);
int		get_next_line(char **line);
int		ft_strstr(char *str, char *to_find);
int		check_charset(char c, char *charset);
int		check_envp(char *c, t_env *envp_n, int n);

// minishell

// execute
int		pipex(int argc, char *argv[], char *envp[]);
void	ft_heredoc(char *limiter);
void	ft_fork(char *argv, char *envp[]);
int		execute(t_input *data);

// builtins
int		yo_pwd(t_input *data);
int		yo_cd(t_input *data);
int		yo_echo(t_input *data);
int		yo_export(t_input *data);
int		yo_env(t_input *data);
int		yo_unset(t_input *data);
int		yo_exit(t_input *data);

//signals
void	sigint_handler(int sign_num);

// others
void	asterisks(t_input *data);

#endif