C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m

NAME		= philo
NAME_b		= philo_bonus

SRC_DIR		= srcs
SRC_FILES	= philo.c \
				philo_init.c \
				philo_utils_1.c \
				philo_utils_2.c 
SRCS		= ${notdir ${SRC_FILES}}

OBJ_DIR		= objs
OBJ_FILES	= ${SRCS:.c=.o}
OBJS		= ${addprefix ${OBJ_DIR}/,${OBJ_FILES}}

INCS		= -I include

GCC			= gcc
RM			= rm -f
RMF			= rm -rf
CFLAGS		= -Wall -Wextra -Werror

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
			@mkdir -p ${OBJ_DIR}
			@echo "${C_YELLOW_B}Compiling...${C_RESET}";
			@${GCC} ${CFLAGS} -c $< ${INCS} -o $@

${NAME}:	${OBJS} 
			@${GCC} ${OBJS} ${INCS} -o ${NAME}
			@echo "${C_GREEN_B}Finished!${C_RESET}";

all:		${NAME}

bonus:
			@make -C ./philo_b
			@cp ./philo_b/philo_bonus .

norm:
			@echo "${C_PURPLE_B}Let's test the Norm!${C_RESET}";
			@norminette
			@echo "${C_PURPLE_B}Done!${C_RESET}";
clean:
			@make -C ./philo_b clean
			@echo "${C_RED_B}Deleting philo o-files...${C_RESET}";
			@${RM} ${OBJS}
			@${RMF} ${OBJ_DIR}
			@echo "${C_RED_B}Philo o-files have been deleted!${C_RESET}";

fclean:		clean
			@make -C ./philo_b fclean
			@echo "${C_RED_B}Deleting philo program...${C_RESET}";
			@${RM} ${NAME} ${NAME_b}
			@echo "${C_RED_B}Philo program has been deleted!${C_RESET}";

re:			fclean all
			@echo "${C_PURPLE_B}Recompiling!${C_RESET}";

.PHONY:		all clean fclean philo_b bonus re .c.o
