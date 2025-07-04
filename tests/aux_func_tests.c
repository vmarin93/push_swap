#include "tests.h"
#include "../push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

void	test_is_sorted()
{
	// Test for a sorted array
	t_Stack	*test_stack = create_stack(5);
	if (test_stack == NULL)
		return;
	int	sorted = -1;
	int	sorted_numbers[5] = {5, 4, 3, 2, 1};
	memcpy(test_stack->numbers, sorted_numbers, sizeof(sorted_numbers));
	test_stack->top = 4;

	sorted = is_sorted(test_stack);
	ASSERT(sorted == 1, "the stack is sorted");
	free_stack(test_stack);

	// Test for an unsorted array
	test_stack = create_stack(5);
	if (test_stack == NULL)
		return;
	sorted = -1;
	int	unsorted_numbers[5] = {2, 1, 5, 4, 3};
	memcpy(test_stack->numbers, unsorted_numbers, sizeof(unsorted_numbers));
	test_stack->top = 4;
	
	sorted = is_sorted(test_stack);
	ASSERT(sorted == 0, "the stack is not sorted");
	free_stack(test_stack);
	TEST_PASS("test_is_sorted");
}

void test_find_smallest()
{
	t_Stack	*test_stack = create_stack(5);
	if (test_stack == NULL)
		return;
	int	smallest;
	int	numbers[5] = {1, 7, -4, 13, 2};
	memcpy(test_stack->numbers, numbers, sizeof(numbers));
	test_stack->top = 4;

	smallest = find_smallest(test_stack);
	ASSERT(smallest == -4, "the function did not return the smallest element in the stack");
	TEST_PASS("test_find_smallest");
	free_stack(test_stack);
}

void test_find_largest()
{
	t_Stack	*test_stack = create_stack(5);
	if (test_stack == NULL)
		return;
	int	largest;
	int	numbers[5] = {41, -32, -55, 21, 24};
	memcpy(test_stack->numbers, numbers, sizeof(numbers));
	test_stack->top = 4;

	largest = find_largest(test_stack);
	ASSERT(largest == 41, "the function did not return the largest element in the stack");
	TEST_PASS("test_find_largest");
	free_stack(test_stack);
}

void test_find_steps_to_top()
{
	// Test number is at the top
	t_Stack	*test_stack = create_stack(11);
	if (test_stack == NULL)
		return;
	int	steps = -1;
	int	numbers[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	memcpy(test_stack->numbers, numbers, sizeof(numbers));
	test_stack->top = 10;
	
	steps = find_steps_to_top(test_stack, 11);
	ASSERT(steps == 0, "did not find the steps to the top when value is the top");

	steps = find_steps_to_top(test_stack, 10);
	ASSERT(steps == 1, "did not find the steps to the top when value is second to the top");

	// Test number is at the bottom
	steps = find_steps_to_top(test_stack, 1);
	ASSERT(steps == 1, "did not find the steps to the top when value is the bottom");

	// Test number is in the middle
	steps = find_steps_to_top(test_stack, 5);
	ASSERT(steps == 5, "did not find the steps to the top when value is the middle");
	free_stack(test_stack);
	TEST_PASS("test_find_steps_to_top");
}

void test_stack_sum()
{
	t_Stack	*test_stack = create_stack(5);
	if (test_stack == NULL)
		return;
	int	sum = 0;
	int	numbers[5] = {1, -2, -3, 4, 5};
	memcpy(test_stack->numbers, numbers, sizeof(numbers));
	test_stack->top = 4;

	sum = stack_sum(test_stack);
	ASSERT(sum == 5, "the sum of the stack values is not computed correctly");
	TEST_PASS("test_stack_sum");
	free_stack(test_stack);
}

void test_find_pair()
{
	t_Stack	*test_stack = create_stack(19);
	if (test_stack == NULL)
		return;
	long	pair;
	int	numbers[19] = {-337, 88, 148, 175, 209, 262, 283, 299, 306, 317, 325, 338, 342, 347, 401, 409, 424, 444, 496};
	memcpy(test_stack->numbers, numbers, sizeof(numbers));
	test_stack->top = 4;

	pair = find_pair(-75, test_stack);
	ASSERT(pair == 88, "incorrect pairing");

	// Find pair to value smaller than smallest in stack
//	pair = find_pair(2, test_stack); 
//	ASSERT(pair == 5, "incorrect pairing for value that's smaller than smallest value in stack");
//
//	// Find pair to value larger than largest in stack
//	pair = find_pair(100, test_stack); 
//	ASSERT(pair == LONG_MIN, "incorrect pairing for value that's larger than largest value in stack");
//
//	// Find pair for negative and positive numbers
//	pair = find_pair(-12, test_stack);
//	ASSERT(pair == 5, "incorrect pairing for negative value");
//	pair = find_pair(-56, test_stack);
//	ASSERT(pair == -44, "incorrect pairing for negative value");
//	
//	// Find pair for null stack
//	pair = find_pair(5, NULL);
//	ASSERT(pair == LONG_MIN, "incorrect pairing for null stack");
//
//	// Find pair to value that is close to 2 different stack values
//	pair = find_pair(20, test_stack); 
//	ASSERT(pair == 21, "incorrect pairing for value that's close to 2 different stack values");
	TEST_PASS("test_find_pair");
	free_stack(test_stack);
}

void test_ft_strdup()
{
	// Duplicate a valid string
	char	*valid_string = "Hello World!";
	char	*duplicate;

	duplicate = ft_strdup(valid_string);
	ASSERT(strcmp(duplicate, valid_string) == 0, "duplicate string is not the same as original");
	free(duplicate);

	// Duplicate a NULL string
	duplicate = ft_strdup(NULL);
	ASSERT(duplicate == NULL, "ft_strdup does not return NULL when passed a null string to duplicate");
	TEST_PASS("test_ft_strdup");
	free(duplicate);
}

void test_register_and_free_ops()
{
	t_Operations	ops = {0};
	char	*op = "test_op";
	int	i = 0;

	// Register 10 operations
	while (i < 10)
	{
		register_ops(op, &ops);
		ASSERT(strcmp(ops.ops[i], op) == 0, "operation was not registered properly");
		i++;
	}
	ASSERT(ops.count == 10, "Operation count is inccorect");

	// Free the ops array
	free_ops(&ops);
	i = 0;
	while (i < 10)
	{
		ASSERT(ops.ops[i] == NULL, "ops array was not set to NULL after freeing");
		i++;
	}
	ASSERT(ops.count == 0, "Operation count was not reset to 0 after freeing");
	TEST_PASS("test_register_and_free_ops");
}

void	test_ft_split()
{
	char	*str = "Hello World!";
	char	*sub;

	sub = ft_split(0, 5, str);
	ASSERT(strcmp(sub, "Hello") == 0, "ft_split did not produce the correct sub_string");
	TEST_PASS("test_ft_split");
}
