NAME	= libftprintf.a

SRCS	= ft_printf.c \
			ft_putchar.c \
			ft_putnbr_base_un.c \
			ft_putstr.c \
			ft_putnbr_base.c \
			ft_putptr_add.c \
			ft_putptr_add_un.c \

OBJS	= ${SRCS:.c=.o}


INCS	= .

LIB		= ar rcs
GCC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c 
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			make -C ./libft all 
			cp libft/libft.a .
			mv libft.a ${NAME}
			${LIB} ${NAME} ${OBJS} 

all:		${NAME}

norm:
			norminette
clean:
			${RM} ${OBJS}
			make -C ./libft clean

fclean:		clean
			${RM} ${NAME}
			make -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re .c.o norm