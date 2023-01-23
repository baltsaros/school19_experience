C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN			=\033[0;32m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m

NAME		= containers
SRCS		= main.cpp
SRCS_B		= main_bonus.cpp

OBJ_DIR		= objs
OBJS_F		= ${SRCS:.cpp=.o}
OBJS		= ${addprefix ${OBJ_DIR}/,${OBJS_F}}

GCC			= c++
RM			= rm -f
RMR			= rm -rf
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	ft std
	@./ft > ft.txt
	@./std > std.txt
	diff ft.txt std.txt

bonus:	ft_b std_b
	diff ft.txt std.txt

dif:
	diff ft.txt std.txt

ft:
	@g++ -D TYPE=ft $(SRCS) -o ft

std:
	@g++ -D TYPE=std $(SRCS) -o std

ft_b:
	@g++ -D TYPE=ft $(SRCS_B) -o ft
	@./ft > ft.txt

std_b:
	@g++ -D TYPE=std $(SRCS_B) -o std
	@./std > std.txt

stack:	ft std
	@./ft stack> ft.txt
	@./std stack> std.txt
	diff ft.txt std.txt

vector:	ft std
	@./ft vector> ft.txt
	@./std vector> std.txt
	diff ft.txt std.txt

map:	ft std
	@./ft map> ft.txt
	@./std map> std.txt
	diff ft.txt std.txt

clean:
	@rm ft
	@rm std
	@rm ft.txt
	@rm std.txt

fclean:	clean

re: fclean all

.PHONY:		all clean fclean re .cpp.o %.cpp%.o ft std bonus dif stack vector map