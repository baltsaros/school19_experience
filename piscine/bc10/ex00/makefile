C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_LIGHT_RED_B	=\033[0;91m
C_WHITE			=\033[0;97m
C_RESET			=\033[0;39m

NAME	= ft_display_file
SRCS	= srcs/main.c \
			srcs/display_file.c \
			srcs/ft_putstr_fd.c

OBJS	= ${SRCS:.c=.o}
INCS	= includes
GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

%.o : %.c
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

test:		re
	@echo "Hello world!" > test_file.txt
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)No file$(C_RESET)" ;
	@./ft_display_file || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Single file: ./test_file.txt$(C_RESET)" ;
	@./ft_display_file ./test_file.txt || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Multiple files: ./test_file.txt ./kek.txt$(C_RESET)" ;
	@./ft_display_file ./test_file.txt ./kek.txt || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Invalid file: ./a$(C_RESET)" ;
	@./a.out || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)On directory: ./srcs/$(C_RESET)" ;
	@./ft_display_file ./srcs/ || true;
	@rm -f test_file.txt ;

.PHONY:		all clean fclean re .c.o test