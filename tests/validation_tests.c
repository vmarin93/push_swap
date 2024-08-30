#include "tests.h"
#include "../push_swap.h"

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

void test_check_for_duplicates()
{
	int	duplicates_middle[7] = {1, 5, 10, 23, 46, 5, 7};
	int	duplicates_front[7] = {1, 1, 5, 23, 46, 10, 7};
	int	duplicates_end[7] = {1, 5, 10, 23, 46, 7, 7};
	int	no_duplicates[7] = {1, 5, 10, 23, 46, 99, 7};
	int	result;

	result = check_for_duplicates(no_duplicates, 7);
	ASSERT(result == 0, "no duplicates in this array");
	result = check_for_duplicates(duplicates_middle, 7);
	ASSERT(result == 1, "number 5 is a duplicate in the middle of this array");
	result = check_for_duplicates(duplicates_front, 7);
	ASSERT(result == 1, "number 1 is a duplicate at the front of this array");
	result = check_for_duplicates(duplicates_end, 7);
	ASSERT(result == 1, "number 7 is a duplicate at the end of this array");
	TEST_PASS("test_check_for_duplicates");
}

void test_fill_stack()
{
	Stack	*test_stack = create_stack(10);
	if (test_stack == NULL)
		exit(1);
	int	numbers[10] = {3, 8, 43, 24, 88, 94, 27, 56, 47, 12};
	int	rev_numbers[10] = {12, 47, 56, 27, 94, 88, 24, 43, 8, 3};
	int	result;

	fill_stack(numbers, 10, test_stack);
	result = memcmp(rev_numbers, test_stack->numbers, 10);
	ASSERT(result == 0, "the numbers inside the stack should be exactly the numbers in the input");
	ASSERT(peek(test_stack) == 3, "the top of the stack should be the 0th index number in the input array");
	TEST_PASS("test_fill_stack");
}
