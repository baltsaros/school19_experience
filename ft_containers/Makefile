C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN			=\033[0;32m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m

NAME		= containers
# SRC_DIR	= srcs
# SRCS		= vector_tests.cpp
# SRCS		= stack_tests.cpp
# SRCS		= map_tests.cpp
# SRCS		= set_tests.cpp
SRCS		= main.cpp
# SRCS		= ${notdir ${SRCS_F}}

OBJ_DIR		= objs
OBJS_F		= ${SRCS:.cpp=.o}
OBJS		= ${addprefix ${OBJ_DIR}/,${OBJS_F}}

GCC			= c++
RM			= rm -f
RMR			= rm -rf
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
INC			= -I .hpp

all:	ft std
	diff ft.txt std.txt

ft:
	@g++ -D TYPE=ft $(SRCS) -o ft
	@./ft > ft.txt

std:
	@g++ -D TYPE=std $(SRCS) -o std
	@./std > std.txt

clean:
	@rm ft
	@rm std
	@rm ft.txt
	@rm std.txt

fclean:	clean

re: fclean all

# ${OBJ_DIR}/%.o : %.cpp
# 			@mkdir -p ${OBJ_DIR}
# 			@printf "${C_GREEN}.${C_RESET}";
# 			@${GCC} ${CPPFLAGS} -c $< -o $@

# ${NAME}:	${OBJS}
# 			@${GCC} ${OBJS} -o ${NAME}
# 			@printf "\n${C_GREEN_B}Finished!${C_RESET}\n";

# all:		${NAME}

# clean:
# 			@echo "${C_RED_B}Deleting o-files...${C_RESET}";
# 			@${RMR} ${OBJ_DIR}
# 			@echo "${C_RED_B}O-files have been deleted!${C_RESET}";

# fclean:		clean
# 			@echo "${C_RED_B}Deleting program ${NAME}...${C_RESET}";
# 			@${RM} ${NAME}
# 			@echo "${C_RED_B}Program ${NAME} has been deleted!${C_RESET}";

# re:			fclean all

.PHONY:		all clean fclean re .cpp.o %.cpp%.o