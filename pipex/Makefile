C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m
NAME	= pipex

SRCS	= ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncmp.c \
			error_check.c \
			ft_free.c \
			pipex.c \

OBJS	= ${SRCS:.c=.o}

INCS	= .

GCC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
			@echo "$(C_YELLOW_B)Compiling...$(C_RESET)";
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			@${GCC} -o ${NAME} ${OBJS}
			@echo "$(C_GREEN_B)Finished!$(C_RESET)";

all:		${NAME}

# bonus:		${OBJS_b}
# 			${LIB} ${NAME} ${OBJS_b}

norm:
			@echo "$(C_PURPLE_B)Let's test the Norm!$(C_RESET)";
			@norminette
			@echo "$(C_PURPLE_B)Done!$(C_RESET)";
clean:
			@echo "$(C_RED_B)Deleting...$(C_RESET)";
			@${RM} ${OBJS}

fclean:		clean
			@echo "$(C_RED_B)Deleting...$(C_RESET)";
			@${RM} ${NAME}
			@echo "$(C_RED_B)Finished!$(C_RESET)";

re:			fclean all

.PHONY:		all clean fclean re .c.o bonus norm
