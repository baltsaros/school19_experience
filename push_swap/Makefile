# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 15:16:10 by abuzdin           #+#    #+#              #
#    Updated: 2022/03/22 09:28:36 by abuzdin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m

NAME	= push_swap

SRCS	= ft_split.c \
			ft_atoi.c \
			ft_strlen.c \
			ft_free.c \
			ft_argv_split.c \
			ft_operations_1.c \
			ft_operations_2.c \
			ft_operations_3.c \
			alloc_check.c \
			input_check.c \
			nodes_1.c \
			nodes_2.c \
			sort_small.c \
			sort_big.c \
			push_swap_utils_1.c \
			push_swap_utils_2.c \
			push_swap_utils_3.c \
			push_swap_utils_4.c \
			push_swap.c \

OBJS	= ${addprefix ${OBJDIR}/,${SRCS:.c=.o}}

OBJDIR	= objs

INCS	= .

GCC		= gcc
RM		= rm -f
RMF		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -g

$(OBJDIR)/%.o : %.c
			@mkdir -p $(OBJDIR)
			@echo "$(C_YELLOW_B)Compiling...$(C_RESET)";
			@${GCC} ${CFLAGS} -c $< -o ${<:%.c=${OBJDIR}/%.o} -I ${INCS}

${NAME}:	${OBJS}
			@${GCC} -o ${NAME} ${OBJS}
			@echo "$(C_GREEN_B)Finished!$(C_RESET)";

all:		${NAME}

bonus:		
			@echo "$(C_YELLOW_B)Compiling the checker...$(C_RESET)";
			@make -C ./checker_bonus
			@cp ./checker_bonus/checker .

norm:
			@echo "$(C_PURPLE_B)Let's test the Norm!$(C_RESET)";
			@norminette
			@echo "$(C_PURPLE_B)Done!$(C_RESET)";
clean:
			@echo "$(C_RED_B)Deleting push_swap o-files...$(C_RESET)";
			@${RM} ${OBJS} ${OBJS_b}
			@${RMF} ${OBJDIR}
			@make -C ./checker_bonus clean
			@echo "$(C_RED_B)Push_swap o-files have been deleted!$(C_RESET)";

fclean:		clean
			@echo "$(C_RED_B)Deleting push_swap...$(C_RESET)";
			@${RM} ${NAME} checker
			@make -C ./checker_bonus fclean
			@echo "$(C_RED_B)Push_swap has been deleted!$(C_RESET)";

re:			fclean all

.PHONY:		all clean fclean re .c.o norm bonus