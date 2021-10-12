SRCS	= main.c ft_atoi.c

OBJS	= ${SRCS: .c=.o}

NAME	= hello

GCC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o: 
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
