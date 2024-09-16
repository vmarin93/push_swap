#include "tests.h"
#include "../push_swap.h"
#include <assert.h>
#include <string.h>

void test_get_input()
{
	char	*argv[] = {"program", "10", "20", "30"};
	int	argc = 4;
	int	*result = get_input(argc, argv);

	ASSERT(result != NULL, "do_int_conversion should return a non-null pointer");
	ASSERT(result[0] == 10, "First element should be 10");
	ASSERT(result[1] == 20, "Second element should be 20");
	ASSERT(result[2] == 30, "Third element should be 30");
	free(result);
	TEST_PASS("test_do_int_conversion");
}

void	test_get_input_len()
{
	char	*input_string = "43 22 56 98 102 5423";
	int	len;

	len = get_input_len(input_string);
	ASSERT(len == 6, "get_input_len did not return the correct length of the input array");
	TEST_PASS("test_get_input_len");

}

void	test_fill_input_matrix()
{
	char	*input_string = "Hello Big Old World!";
	char	**input_matrix;

	input_matrix = fill_input_matrix(input_string, 4);
	ASSERT(strcmp(input_matrix[0], "Hello") == 0, "get_input_matrix did not correctly extract first word from input");
	ASSERT(strcmp(input_matrix[1], "Big") == 0, "get_input_matrix did not correctly extract second word from input");
	ASSERT(strcmp(input_matrix[2], "Old") == 0, "get_input_matrix did not correctly extract third word from input");
	ASSERT(strcmp(input_matrix[3], "World!") == 0, "get_input_matrix did not correctly extract last word from input");
	free_input_matrix(input_matrix);
	TEST_PASS("test_fill_input_matrix");
}

void	test_validate_from_array()
{
	char	*input_string = "3 4 6 8 9 74 -56 +495";
	int	expected_input[8] = {3, 4, 6, 8, 9, 74, -56, +495};
	int	*input;
	int	i;

	input = validate_from_array(input_string, 8);
	i = 0;
	while (i < 8)
	{
		ASSERT(input[i] == expected_input[i], "validate_from_array did not produce expected array of integers");
		i++;
	}
	free(input);
	TEST_PASS("test_validate_from_array");
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
	t_Stack	*test_stack = create_stack(10);
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
	free_stack(test_stack);
}
