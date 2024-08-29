SRC = push_swap.c ft_strtol.c ft_stack.c hardcoded_sorts.c temp.c

OBJS := ${SRC:%.c=%.o}

TEST_SRC = ./tests/validation_tests.c
TEST_OBJS = $(TEST_SRC:%.c=%.o)

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

test: $(OBJS) $(TEST_OBJS)
	${CC} ${CCFLAGS} ${OBJS} ${TEST_OBJS} -o validation_test

%.o: %.c
	${CC} ${CPPFLAGS} ${CCFLAGS} -o $@ -c $<

clean:
	${RM} ${OBJS} ${TEST_OBJS}

fclean:
	${RM} ${NAME} validation_test

re: fclean all test

.PHONY: all clean fclean re
