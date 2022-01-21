NAME	= libftprint.a

SRCS	= ft_printf.c \

OBJS	= ${SRCS:.c=.o}


INCS	= .

LIB		= ar rcs
GCC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c 
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			make all ./libft
			cp libft/libft.a .
			mv libft.a ${NAME}
			${LIB} ${NAME} ${OBJS} 

all:		${NAME}


norm:
			norminette
clean:
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re .c.o norm