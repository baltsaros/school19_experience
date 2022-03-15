# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 15:16:10 by abuzdin           #+#    #+#              #
#    Updated: 2022/03/15 12:25:21 by abuzdin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m

NAME	= checker

SRCS	= ft_split.c \
			ft_atoi.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_calloc.c \
			ft_free.c \
			ft_argv_split.c \
			ft_commands.c \
			ft_operations_1.c \
			ft_operations_2.c \
			ft_operations_3.c \
			alloc_check.c \
			checker_utils.c \
			checker_utils_2.c \
			get_next_line.c \
			input_check.c \
			nodes.c \
			checker.c \

OBJS	= ${SRCS:.c=.o}

INCS	= .

GCC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -g

%.o : %.c
			@echo "$(C_YELLOW_B)Compiling...$(C_RESET)";
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			@${GCC} -o ${NAME} ${OBJS}
			@echo "$(C_GREEN_B)Finished!$(C_RESET)";

all:		${NAME}

norm:
			@echo "$(C_PURPLE_B)Let's test the Norm!$(C_RESET)";
			@norminette
			@echo "$(C_PURPLE_B)Done!$(C_RESET)";
clean:
			@echo "$(C_RED_B)Deleting...$(C_RESET)";
			@${RM} ${OBJS} ${OBJS_b}
			@echo "$(C_RED_B)o-files have been deleted!$(C_RESET)";

fclean:		clean
			@echo "$(C_RED_B)Deleting...$(C_RESET)";
			@${RM} ${NAME}
			@echo "$(C_RED_B)The program has been deleted!$(C_RESET)";

re:			fclean all

.PHONY:		all clean fclean re .c.o norm