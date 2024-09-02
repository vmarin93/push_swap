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
