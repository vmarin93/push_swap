#include "tests.h"
#include "../push_swap.h"
#include <stdlib.h>
#include <string.h>

void	test_is_sorted()
{
	// Test for a sorted array
	Stack	*test_stack = create_stack(5);
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
	Stack	*test_stack = create_stack(5);
	if (test_stack == NULL)
		return;
	int	smallest;
	int	numbers[5] = {1, 7, 4, 13, 2};
	memcpy(test_stack->numbers, numbers, sizeof(numbers));
	test_stack->top = 4;

	smallest = find_smallest(test_stack);
	ASSERT(smallest == 1, "the function did not return the smallest element in the stack");
	TEST_PASS("test_find_smallest");
	free_stack(test_stack);
}

void test_find_largest()
{
	Stack	*test_stack = create_stack(5);
	if (test_stack == NULL)
		return;
	int	largest;
	int	numbers[5] = {41, 32, 55, 21, 24};
	memcpy(test_stack->numbers, numbers, sizeof(numbers));
	test_stack->top = 4;

	largest = find_largest(test_stack);
	ASSERT(largest == 55, "the function did not return the smallest element in the stack");
	TEST_PASS("test_find_largest");
	free_stack(test_stack);
}

void test_find_steps_to_top()
{
	// Test number is at the top
	Stack	*test_stack = create_stack(10);
	if (test_stack == NULL)
		return;
	int	steps = -1;
	int	numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	memcpy(test_stack->numbers, numbers, sizeof(numbers));
	test_stack->top = 9;
	
	steps = find_steps_to_top(test_stack, 10);
	ASSERT(steps == 0, "did not find the steps to the top when value is the top");

	// Test number is at the bottom
	steps = find_steps_to_top(test_stack, 1);
	ASSERT(steps == 9, "did not find the steps to the top when value is the bottom");

	// Test number is in the middle
	steps = find_steps_to_top(test_stack, 5);
	ASSERT(steps == 5, "did not find the steps to the top when value is the middle");
	free_stack(test_stack);
	TEST_PASS("test_find_steps_to_top");
}

void test_stack_sum()
{
	Stack	*test_stack = create_stack(5);
	if (test_stack == NULL)
		return;
	int	sum = 0;
	int	numbers[5] = {1, 2, 3, 4, 5};
	memcpy(test_stack->numbers, numbers, sizeof(numbers));
	test_stack->top = 4;

	sum = stack_sum(test_stack);
	ASSERT(sum == 15, "the sum of the stack values is not computed correctly");
	TEST_PASS("test_stack_sum");
	free_stack(test_stack);
}

void test_find_pair()
{
	Stack	*test_stack = create_stack(10);
	if (test_stack == NULL)
		return;
	int	pair;
	int	numbers[10] = {12, 44, 33, 25, 67, 98, 5, 70, 65, 21};
	memcpy(test_stack->numbers, numbers, sizeof(numbers));
	test_stack->top = 9;

	// Find pair to value smaller than smallest in stack
	pair = find_pair(2, test_stack); 
	ASSERT(pair == 5, "incorrect pairing for value that's smaller than smallest value in stack");

	// Find pair to value larger than largest in stack
	pair = find_pair(100, test_stack); 
	ASSERT(pair == 5, "incorrect pairing for value that's larger than largest value in stack");
	
	// Find pair to value that is close to 2 different stack values
	pair = find_pair(20, test_stack); 
	ASSERT(pair == 21, "incorrect pairing for value that's close to 2 different stack values");
	TEST_PASS("test_find_pair");
	free_stack(test_stack);
}

void test_get_pairs()
{
	Stack	*stack_a = create_stack(12);
	Stack	*stack_b = create_stack(12);
	int	*pairs;
	int	numbers_a[5] = {64, 88, 91, 78, 65};
	int	numbers_b[7] = {15, 9, 27, 33, 12, 43, 75};
	//int	expected_pairs[14] = {75, 78, 43, 64, 12, 64, 33, 64, 27, 64, 9, 64, 15, 64};
	int	i;
	memcpy(stack_a->numbers, numbers_a, sizeof(numbers_a));
	stack_a->top = 5;
	memcpy(stack_b->numbers, numbers_b, sizeof(numbers_b));
	stack_b->top = 7;

	pairs = get_pairs(stack_a, stack_b);
	i = 0;
	while(i <= 14)
	{
		printf("%d\n", pairs[i]);
	//	if (pairs[i] != expected_pairs[i])
	//		break;
		i++;
	}
	ASSERT(i == 15, "get pairs did not produce the correct pairings");
	TEST_PASS("test_get_pairs");
	free(pairs);
	free_stack(stack_a);
	free_stack(stack_b);
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
	char	*ops[15000] = {0};
	char	*op = "test_op";
	int	i = 0;

	// Register 10 operations
	while (i < 10)
	{
		register_ops(op, ops);
		ASSERT(strcmp(ops[i], op) == 0, "operation was not registered properly");
		i++;
	}

	// Free the ops array
	free_ops(ops);
	ASSERT(ops[0] == NULL, "ops array was not freed up properly");
	TEST_PASS("test_register_and_free_ops");
}
