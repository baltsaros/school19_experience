C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN			=\033[0;32m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m

NAME		= minishell

SRC_DIR		= srcs
SRC_FILES	= minishell.c \
				minishell_utils.c \
				nodes_1.c \
				nodes_2.c \
				alloc_check.c \
				ft_free.c \
				ft_split_space.c \
				signal.c \
				execute.c \
				builtins.c \
				get_next_line.c \
				parsing_utils.c \
				wildcard.c \
				parsing.c
SRCS		= ${notdir ${SRC_FILES}}

OBJ_DIR		= objs
OBJ_FILES	= ${SRCS:.c=.o}
OBJS		= ${addprefix ${OBJ_DIR}/,${OBJ_FILES}}

INCS		= -Iinclude -Ilibft

GCC			= gcc
RM			= rm -f
RMF			= rm -rf
CFLAGS		= -Wall -Wextra -Werror

all:		libft ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
			@mkdir -p ${OBJ_DIR}
			@printf "${C_GREEN}.${C_RESET}";
			@${GCC} ${CFLAGS} -c $< ${INCS} -o $@

${NAME}:	${OBJS} 
			@${GCC} ${OBJS} ${INCS} libft/libft.a -lreadline -o ${NAME}
			@printf "\n${C_GREEN_B}Finished!${C_RESET}\n";

libft:
			@make -C ./libft
norm:
			@echo "${C_PURPLE_B}Let's test the Norm!${C_RESET}";
			@norminette
			@echo "${C_PURPLE_B}Done!${C_RESET}";
clean:
			@echo "${C_RED_B}Deleting minishell o-files...${C_RESET}";
			@make -C ./libft clean
			@${RM} ${OBJS}
			@${RMF} ${OBJ_DIR}
			@echo "${C_RED_B}Minishell o-files have been deleted!${C_RESET}";

fclean:		clean
			@make -C ./libft fclean
			@echo "${C_RED_B}Deleting minishell program...${C_RESET}";
			@${RM} ${NAME}
			@echo "${C_RED_B}Minishell program has been deleted!${C_RESET}";

re:			fclean all

.PHONY:		all clean fclean libft re .c.o
