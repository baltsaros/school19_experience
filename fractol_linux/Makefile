NAME	= fractol

SRCS	= main.c \
			ft_mini_atoi.c \
			ft_strncmp.c \
			color.c \

OBJS	= ${SRCS:.c=.o}

INCS	= mlx_linux\

GCC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
			${GCC} ${CFLAGS} -Imlx_linux -c $< -o $@ 
 
${NAME}:	${OBJS}
			$(GCC) $(OBJS) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

bonus:

re:			fclean all

.PHONY:		all clean fclean bonus re .c.o
