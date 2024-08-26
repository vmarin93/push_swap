SRC = src/push_swap.c src/ft_strtoi.c  src/ft_stack.c src/hardcoded_sorts.c

OBJS := ${SRC:%.c=%.o}

NAME = push_swap

CC = gcc

CCFLAGS = -Wall -Wextra -Werror 

INC_DIR = .

CPPFLAGS = -I${INC_DIR}

RM = rm -f

all: ${NAME}
	${RM} ${OBJS}

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
