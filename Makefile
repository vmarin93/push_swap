SRC = aux.c \
      ops_aux.c \
      push_swap.c \
      sort_aux1.c \
      sort_aux2.c \
      sort_size_3.c \
      sort_size_4.c \
      sort_size_5.c \
      stack.c \
      stack_ops.c \
      sort_stack.c \
      validate_input.c \
      ft_strtol.c 
OBJS := ${SRC:%.c=%.o}

TEST_SRC = ./tests/validation_tests.c ./tests/main.c ./tests/sorting_tests.c ./tests/aux_func_tests.c
TEST_OBJS = $(TEST_SRC:%.c=%.o)
SHARED_OBJS = $(filter-out push_swap.o, ${OBJS})

NAME = push_swap
TEST_NAME = test

CC = gcc
CCFLAGS = -Wall -Wextra -Werror -g
INC_DIR = .
CPPFLAGS = -I${INC_DIR}

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CCFLAGS} ${OBJS} -o ${NAME}

${TEST_NAME}: ${TEST_OBJS} ${SHARED_OBJS}
	${CC} ${CCFLAGS} ${TEST_OBJS} ${SHARED_OBJS} -o ${TEST_NAME}

%.o: %.c
	${CC} ${CPPFLAGS} ${CCFLAGS} -o $@ -c $<

clean:
	${RM} ${OBJS} ${TEST_OBJS}

fclean:
	${RM} ${NAME} ${TEST_NAME}

re: fclean all

.PHONY: all clean fclean re test
