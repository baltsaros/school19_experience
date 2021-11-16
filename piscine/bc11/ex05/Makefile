C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_LIGHT_RED_B	=\033[0;91m
C_WHITE			=\033[0;97m
C_RESET			=\033[0;39m

NAME	= do-op
SRCS	= srcs/main.c \
			srcs/ft_atoi.c \
			srcs/ft_check_operator.c \
			srcs/ft_operation.c \
			srcs/ft_putchar.c \
			srcs/ft_putnbr.c \
			srcs/ft_putstr.c
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
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Addition: 5 + 37$(C_RESET)";
	@./${NAME} 5 + 37 || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Addition: 5aa3 + bbb37$(C_RESET)";
	@./${NAME} 5aa3 + bbb37 || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Substraction: 55 - 5$(C_RESET)";
	@./${NAME} 55 - 5 || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Multiplication: 5 * 5$(C_RESET)";
	@./${NAME} 5 "*" 5 || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Division: 25 / 5$(C_RESET)";
	@./${NAME} 25 / 5 || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Division by zero: 25 / 0$(C_RESET)";
	@./${NAME} 25 / 0 || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Modulo: 25 % 4$(C_RESET)";
	@./${NAME} 25 % 4 || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Modulo by zero: 25 % 0$(C_RESET)";
	@./${NAME} 25 % 0 || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Invalid operator: 25 p 4$(C_RESET)";
	@./${NAME} 25 p 4|| true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Invalid arguments: do-op % 4$(C_RESET)";
	@./${NAME} || true;
	@echo "[$(C_YELLOW_B)TESTING$(C_RESET)] $(C_WHITE)Invalid arguments: do-op 1 % 4$(C_RESET)";
	@./${NAME} 1 || true;

.PHONY:		all clean fclean re test .c.o
