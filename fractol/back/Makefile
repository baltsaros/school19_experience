# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abuzdin <abuzdin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 12:50:23 by abuzdin           #+#    #+#              #
#    Updated: 2022/03/29 16:58:37 by abuzdin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m

NAME	= fractol

SRCS	= fractol.c \
			fractol_utils.c \
			hooks.c \
			check_error.c \
			set_init.c \
			set_render.c \

# SRC_FILES	= ${shell find ${SRC_DIR} -name '*.c'}
SRC_DIR		= srcs

OBJ_FILES	= ${SRCS:.c=.o}
OBJ_DIR		= objs


OBJS	= ${addprefix ${OBJ_DIR}/,${OBJ_FILES}}

INCS	= -I minilibx

GCC		= gcc
RM		= rm -f
RMF		= rm -rf
CFLAGS	= -Wall -Wextra -Werror

${OBJ_DIR}/%.o : %.c
			@mkdir -p $(OBJ_DIR)
			@echo "$(C_YELLOW_B)Compiling...$(C_RESET)";
			@${GCC} ${CFLAGS} ${INCS} -c $< -o ${<:%.c=${OBJ_DIR}/%.o}

${NAME}:	${OBJS}
			@$(GCC) $(OBJS) ${INCS} -L minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			@echo "$(C_GREEN_B)Finished!$(C_RESET)";

all:		${NAME}

norm:
			@echo "$(C_PURPLE_B)Let's test the Norm!$(C_RESET)";
			@norminette
			@echo "$(C_PURPLE_B)Done!$(C_RESET)";
clean:
			@echo "$(C_RED_B)Deleting fractol o-files...$(C_RESET)";
			@${RM} ${OBJS} ${OBJS_b}
			@${RMF} ${OBJDIR}
			@echo "$(C_RED_B)Fractol o-files have been deleted!$(C_RESET)";

fclean:		clean
			@echo "$(C_RED_B)Deleting fractol...$(C_RESET)";
			@${RM} ${NAME}
			@echo "$(C_RED_B)Fractol has been deleted!$(C_RESET)";

re:			fclean all

.PHONY:		all clean fclean bonus re .c.o
