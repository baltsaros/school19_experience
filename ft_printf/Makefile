NAME	= libftprint.a

SRCS	= ft_printf.c \

OBJS	= ${SRCS:.c=.o}


INCS	= .

LIB		= 	make all libft
			cp libft/libft.a .
			mv libft.a libftprint.a
			ar rcs
GCC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c 
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS} 

all:		${NAME}

bonus:		${OBJS_b}
			${LIB} ${NAME} ${OBJS_b}

norm:
			norminette
clean:
			${RM} ${OBJS} ${OBJS_b}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re .c.o bonus norm