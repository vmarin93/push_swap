#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../push_swap.h"

#define ANSI_COLOR_RED		"\x1b[31m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_RESET	"\x1b[0m"

#define ASSERT(condition, message) do { \
	if (!(condition)) { \
		fprintf(stderr, ANSI_COLOR_RED "Assertion failed: %s\n" ANSI_COLOR_RESET, message); \
		exit(1); \
	} \
} while (0)

#define TEST_PASS(test_name) printf(ANSI_COLOR_GREEN "PASS: %s\n" ANSI_COLOR_RESET, test_name) 
#define TEST_FAIL(test_name) printf(ANSI_COLOR_RED "FAIL: %s\n" ANSI_COLOR_RESET test_name)

int *do_int_conversion(int argc, char *argv[]);
void check_for_duplicates(int *input, int len);
void fill_stack(int *input, int len, Stack *stack_a);

void test_do_int_conversion()
{
	char	*argv[] = {"program", "10", "20", "30"};
	int	argc = 4;
	int	*result = do_int_conversion(argc, argv);

	ASSERT(result != NULL, "do_int_conversion should return a non-null pointer");
	ASSERT(result[0] == 10, "First element should be 10");
	ASSERT(result[1] == 20, "Second element should be 20");
	ASSERT(result[2] == 30, "Third element should be 30");
	free(result);
	TEST_PASS("test_do_int_conversion");
}

int main()
{
	test_do_int_conversion();
}
