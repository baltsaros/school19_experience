NAME	= libftprint.a

SRCS	= ft_printf.c \

SRCS_b	= \

OBJS	= ${SRCS:.c=.o}

OBJS_b	= ${SRCS_b:.c=.o}

INCS	= .

LIB		= ar rcs
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