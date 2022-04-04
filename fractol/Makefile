C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m

NAME		= fractol

SRC_DIR		= srcs
SRC_FILES	= ${shell find ${SRC_DIR} -name '*.c'}
SRCS		= ${notdir ${SRC_FILES}}

OBJ_DIR		= objs
OBJ_FILES	= ${SRCS:.c=.o}
OBJS		= ${addprefix ${OBJ_DIR}/,${OBJ_FILES}}

INCS		= -Iminilibx -Iinclude -Ilibft

GCC			= gcc
RM			= rm -f
RMF			= rm -rf
CFLAGS		= -Wall -Wextra -Werror

all:		libft ${NAME}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c
			@mkdir -p ${OBJ_DIR}
			@echo "${C_YELLOW_B}Compiling...${C_RESET}";
			@${GCC} ${CFLAGS} -c $< ${INCS} -o $@

${NAME}:	${OBJS} 
			@${GCC} ${OBJS} ${INCS} libft/libft.a -Lminilibx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
			@echo "${C_GREEN_B}Finished!${C_RESET}";

libft:
			@make -C ./libft
norm:
			@echo "${C_PURPLE_B}Let's test the Norm!${C_RESET}";
			@norminette
			@echo "${C_PURPLE_B}Done!${C_RESET}";
clean:
			@echo "${C_RED_B}Deleting fractol o-files...${C_RESET}";
			@make -C ./libft clean
			@${RM} ${OBJS}
			@${RMF} ${OBJ_DIR}
			@echo "${C_RED_B}Fractol o-files have been deleted!${C_RESET}";

fclean:		clean
			@make -C ./libft fclean
			@echo "${C_RED_B}Deleting fractol program...${C_RESET}";
			@${RM} ${NAME}
			@echo "${C_RED_B}Fractol program has been deleted!${C_RESET}";

re:			fclean all
			@echo "${C_PURPLE_B}Recompiling!${C_RESET}";

.PHONY:		all clean fclean libft re .c.o
