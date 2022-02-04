# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 12:08:26 by abuzdin           #+#    #+#              #
#    Updated: 2022/01/31 17:32:17 by abuzdin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_output_char.c \
			ft_output_str.c \
			ft_output_nbr.c \
			ft_output_nbr_un.c \
			ft_output_hex.c \
			ft_output_hex_x.c \
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
			make -C ./libft
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

bonus:		${OBJS}
			make -C ./libft bonus
			cp libft/libft.a .
			mv libft.a ${NAME}
			${LIB} ${NAME} ${OBJS} 

re:			fclean all

.PHONY:		all clean fclean re .c.o norm