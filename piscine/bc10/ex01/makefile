C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_LIGHT_RED_B	=\033[0;91m
C_WHITE			=\033[0;97m
C_RESET			=\033[0;39m

NAME	= ft_cat
SRCS	= srcs/main.c \
			srcs/ft_cat.c \
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

re:			clean all

test:		re
	@echo "$(C_PURPLE_B)Creating a test file 1...$(C_RESET)";
	@echo "Hello there! This is test_file1" > test_file1.txt
	@echo "$(C_PURPLE_B)Creating a test file 2...$(C_RESET)";
	@echo "Hello again! This is test_file2" > test_file2.txt
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Single file: test_file1.txt$(C_RESET)";
	@./${NAME} test_file1.txt || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Multiple files: test_file1.txt test_file2.txt$(C_RESET)";
	@./${NAME} test_file1.txt test_file2.txt || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Invalid programme name: ./a.out$(C_RESET)";
	@./a.out || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)On directory: ./srcs/$(C_RESET)";
	@./${NAME} ./srcs/ || true;
	@${RM} test_file1.txt test_file2.txt;

.PHONY:		all clean fclean re test
