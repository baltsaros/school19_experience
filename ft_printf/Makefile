NAME	= libftprintf.a

SRCS	= ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_output_char.c \
			ft_output_str.c \
			ft_output_nbr.c \
			ft_output_nbr_un.c \
			ft_output_hex.c \
			ft_output_hexX.c \
			ft_output_ptr.c \

OBJS	= ${SRCS:.c=.o}


INCS	= .

LIB		= ar rcs
GCC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c 
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			make -C ./libft && make -C ./libft bonus 
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