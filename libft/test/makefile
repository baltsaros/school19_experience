NAME	= libft.a

SRCS	= srcs/ft_isalpha.c \
			srcs/ft_isdigit.c \
			srcs/ft_isalnum.c \
			srcs/ft_isascii.c \
			srcs/ft_isprint.c \
			srcs/ft_strlen.c \
			srcs/ft_memset.c \
			srcs/ft_bzero.c \
			srcs/ft_memcpy.c \
			srcs/ft_memmove.c \
			srcs/ft_strlcpy.c \
			srcs/ft_strlcat.c \
			srcs/ft_toupper.c \
			srcs/ft_tolower.c \
			srcs/ft_strchr.c \
			srcs/ft_strrchr.c \
			srcs/ft_strncmp.c \
			srcs/ft_memchr.c \
			srcs/ft_memcmp.c \
			srcs/ft_strnstr.c \
			srcs/ft_atoi.c \
			srcs/ft_calloc.c \
			srcs/ft_strdup.c \

OBJS	= ${SRCS:.c=.o}

INCS	= includes

LIB		= ar rcs
GCC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c 
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS} 

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re .c.o