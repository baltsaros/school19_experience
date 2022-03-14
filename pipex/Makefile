# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 11:07:46 by abuzdin           #+#    #+#              #
#    Updated: 2022/03/14 16:50:21 by abuzdin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m

NAME	= pipex

SRCS	= ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strncmp.c \
			ft_strlen.c \
			ft_free.c \
			ft_calloc.c \
			alloc_check.c \
			pipex_utils.c \
			pipex.c \

SRCS_b	= ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strncmp.c \
			ft_strlen.c \
			ft_calloc.c \
			alloc_check.c \
			ft_free.c \
			get_next_line.c \
			pipex_utils.c \
			pipex_bonus.c \

OBJS	= ${SRCS:.c=.o}

OBJS_b	= ${SRCS_b:.c=.o}

INCS	= .

GCC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
			@echo "$(C_YELLOW_B)Compiling...$(C_RESET)";
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			@${GCC} -o ${NAME} ${OBJS}
			@echo "$(C_GREEN_B)Finished!$(C_RESET)";

all:		${NAME}

bonus:		${OBJS_b}
			@${GCC} -o ${NAME} ${OBJS_b}
			@echo "$(C_GREEN_B)Finished (bonus)!$(C_RESET)";

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

.PHONY:		all clean fclean re .c.o bonus norm
