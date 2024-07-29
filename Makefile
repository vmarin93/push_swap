SRC = push_swap.c ft_strtoi.c ft_stack.c

OBJS := ${SRC:%.c=%.o}

NAME = push_swap

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

INC_DIR = .

CPPFLAGS = -I${INC_DIR}

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CCFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CPPFLAGS} ${CCFLAGS} -o $@ -c $<

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
