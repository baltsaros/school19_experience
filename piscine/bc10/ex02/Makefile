C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_LIGHT_RED_B	=\033[0;91m
C_WHITE			=\033[0;97m
C_RESET			=\033[0;39m

NAME	= ft_tail
SRCS	= srcs/main.c \
			srcs/tail.c \
			srcs/ft_putstr_fd.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

%.o : %.c
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re test .c.o 
