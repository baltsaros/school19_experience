NAME	= pipex

SRCS	= ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strncmp.c \
			main.c \

OBJS	= ${SRCS:.c=.o}

INCS	= .

GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}
			@echo Compiling...
			
${NAME};	${OBJS}
			${NAME} ${OBJS}

all:		${NAME}

# bonus:		${OBJS_b}
# 			${LIB} ${NAME} ${OBJS_b}

norm:
			norminette
clean:
			${RM} ${OBJS} ${OBJS_b}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re .c.o bonus norm
