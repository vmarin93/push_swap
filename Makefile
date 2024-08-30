SRC = push_swap.c ft_strtol.c ft_stack.c hardcoded_sorts.c temp.c

OBJS := ${SRC:%.c=%.o}

TEST_SRC = ./tests/validation_tests.c ./tests/main.c
TEST_OBJS = $(TEST_SRC:%.c=%.o)

NAME = push_swap

TEST_NAME = test

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

INC_DIR = .

CPPFLAGS = -I${INC_DIR}

RM = rm -f

all: ${NAME} ${TEST_NAME}
	${RM} ${OBJS}

${NAME}: ${OBJS}
	${CC} ${CCFLAGS} ${OBJS} -o ${NAME}

${TEST_NAME}: $(OBJS) $(TEST_OBJS)
	${CC} ${CCFLAGS} ${OBJS} ${TEST_OBJS} -o ${TEST_NAME}

%.o: %.c
	${CC} ${CPPFLAGS} ${CCFLAGS} -o $@ -c $<

clean:
	${RM} ${OBJS} ${TEST_OBJS}

fclean:
	${RM} ${NAME} ${TEST_NAME}

re: fclean all

.PHONY: all clean fclean re
