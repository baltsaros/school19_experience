NAME	= fractol

SRCS	= main.c \

OBJS	= ${SRCS:.c=.o}

INCS	= -I minilibx\

GCC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -g

%.o : %.c
			${GCC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:	${OBJS}
			$(GCC) $(OBJS) ${INCS} -L minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

# bonus:

re:			fclean all

.PHONY:		all clean fclean bonus re .c.o
