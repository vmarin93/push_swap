#include "tests.h"
#include "../push_swap.h"
#include <stdlib.h>
#include <string.h>

void test_sort_size_2()
{
	Stack	*stack_a = create_stack(2);
	Stack	*stack_b = create_stack(2);
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	Operations ops = {0};

	stack_a->numbers[0] = 42;
	stack_a->numbers[1] = 43;
	stack_a->top = 1;
	sort_stack(stack_a, stack_b, &ops);
	ASSERT(stack_a->numbers[0] == 43, "the 2 element stack was not sorted");
	ASSERT(stack_a->numbers[1] == 42, "the 2 element stack was not sorted");
	ASSERT(ops.count == 1, "it took more than 1 operation to sort a stack of 2 elements");
	TEST_PASS("test_sort_size_2");

	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}

void test_sort_size_3()
{
	Stack	*stack_a = create_stack(3);
	Stack	*stack_b = create_stack(3);
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	Operations ops = {0};
	
	stack_a->numbers[0] = 75;
	stack_a->numbers[1] = 56;
	stack_a->numbers[2] = 89;
	stack_a->top = 2;
	sort_stack(stack_a, stack_b, &ops);
	ASSERT(stack_a->numbers[0] == 89, "the 3 element stack was not sorted");
	ASSERT(stack_a->numbers[1] == 75, "the 3 element stack was not sorted");
	ASSERT(stack_a->numbers[2] == 56, "the 3 element stack was not sorted");
	ASSERT(ops.count == 1, "too many ops to sort stack. should be one op only");
	TEST_PASS("test_sort_size_3");
	
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}

void test_sort_size_4()
{
	Stack	*stack_a = create_stack(4);
	Stack	*stack_b = create_stack(4);
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	;
	Operations ops = {0};
	int	i;
	int	numbers[4] = {42, 67, 31, 84};
	int	sorted_numbers[4] = {84, 67, 42, 31};
	memcpy(stack_a->numbers, numbers, sizeof(numbers));
	stack_a->top = 3;

	// check the stack is sorted
	sort_size_4(stack_a, stack_b, &ops);
	i = stack_a->top;
	while (i >= 0)
	{
		if (stack_a->numbers[i] != sorted_numbers[i])	
			break;
		i--;
	}
	ASSERT(i == -1, "the 4 element stack was not sorted");

	// check for optimal moves usage
	ASSERT(ops.count == 4, "stack was not sorted in the most optimal way");
	TEST_PASS("test_sort_size_4");
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}

void test_sort_size_5()
{
	Stack	*stack_a = create_stack(5);
	Stack	*stack_b = create_stack(5);
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	Operations ops = {0};
	int	i;
	int	numbers[5] = {43, 89, 54, 12, 32};
	int	sorted_numbers[5] = {89, 54, 43, 32, 12};
	memcpy(stack_a->numbers, numbers, sizeof(numbers));
	stack_a->top = 4;

	// check the stack is sorted
	sort_size_5(stack_a, stack_b, &ops);
	i = stack_a->top;
	while (i >= 0)
	{
		if (stack_a->numbers[i] != sorted_numbers[i])
			break;
		i--;
	}
	ASSERT(i == -1, "the 5 element stack was not sorted");

	// check for optimal moves usage
	ASSERT(ops.count == 8, "stack was not sorted in the most optimal way");
	TEST_PASS("test_sort_size_5");
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}

void test_push_to_b()
{
	Stack	*stack_a = create_stack(12);
	Stack	*stack_b = create_stack(12);
	if (stack_a == NULL || stack_b == NULL)
		return;
	Operations	ops = {0};
	int	i;
	int	numbers[12] = {43, 12, 33, 65, 78, 91, 27, 88, 9, 15, 64, 75};
	int	keepers[5] = {65, 78, 91, 88, 64};
	memcpy(stack_a->numbers, numbers, sizeof(numbers));
	stack_a->top = 11;

	push_to_b(stack_a, stack_b, &ops);
	i = stack_a->top;
	while (i >= 0)
	{
		if (stack_a->numbers[i] != keepers[i])
			break;
		i--;
	}
	ASSERT(i = -1, "push_to_b did not transfer the correct values from stack_a to stack_b");
	TEST_PASS("test_push_to_b");
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}

void test_fill_go_top_box()
{
	Box	go_top;
	Stack	*stack_a = create_stack(12);
	Stack	*stack_b = create_stack(12);
	if (stack_a == NULL || stack_b == NULL)
		return ;
	int	numbers_a[5] = {64, 88, 91, 78, 65};
	int	numbers_b[7] = {15, 9, 27, 33, 12, 43, 75};
	memcpy(stack_a->numbers, numbers_a, sizeof(numbers_a));
	stack_a->top = 4;
	memcpy(stack_b->numbers, numbers_b, sizeof(numbers_b));
	stack_b->top = 6;

	fill_go_top_box(stack_a, stack_b, &go_top);
	ASSERT(go_top.value_top_a == 78, "incorrect value_top_a");
	ASSERT(go_top.value_top_b == 75, "incorrect value_top_b");
	ASSERT(go_top.steps_top_a == 1, "incorrect steps_top_a");
	ASSERT(go_top.steps_top_b == 0, "incorrect steps_top_b");
	TEST_PASS("test_fill_go_top_box");
	free_stack(stack_a);
	free_stack(stack_b);
}

void test_move_to_top_a()
{
	Box	go_top;
	Operations	ops = {0};
	Stack	*stack_a = create_stack(5);
	if (stack_a == NULL)
		return ;
	int	numbers[5] = {64, 88, 91, 78, 65};
	memcpy(stack_a->numbers, numbers, sizeof(numbers));
	stack_a->top = 4;
	go_top.value_top_a = 88;
	go_top.steps_top_a = 3;

	move_to_top_a(stack_a, &go_top, &ops);
	ASSERT(peek(stack_a) == 88, "value was not moved to the top of stack a");
	TEST_PASS("test_move_to_top_a");
	free_stack(stack_a);
	free_ops(&ops);
}

void test_move_to_top_b()
{
	Box	go_top;
	Operations	ops = {0};
	Stack	*stack_b = create_stack(7);
	if (stack_b == NULL)
		return ;
	int	numbers[7] = {15, 9, 27, 33, 12, 43, 75};
	memcpy(stack_b->numbers, numbers, sizeof(numbers));
	stack_b->top = 6;
	go_top.value_top_b = 27;
	go_top.steps_top_b = 4;

	move_to_top_b(stack_b, &go_top, &ops);
	ASSERT(peek(stack_b) == 27, "value was not moved to the top of stack b");
	TEST_PASS("test_move_to_top_b");
	free_stack(stack_b);
	free_ops(&ops);
}

void test_sort_stack()
{
	int	i;
	Stack	*stack_a = create_stack(12);
	Stack	*stack_b = create_stack(12);
	if (stack_a == NULL || stack_b == NULL)
		return ;
	Operations	ops = {0};
	int	numbers[12] = {43, 12, 33, 65, 78, 91, 27, 88, 9, 15, 64, 75};
	int	sorted_numbers[12] = {91, 88, 78, 75, 65, 64, 43, 33, 27, 15, 12, 9};
	fill_stack(numbers, 12, stack_a);

	sort_stack(stack_a, stack_b, &ops);
	i = 0;
	while (i < 12)
	{
		if (stack_a->numbers[i] != sorted_numbers[i])
			break;
		i++;
	}
	ASSERT(i = 11, "the stack was not sorted");
	TEST_PASS("test_sort_stack");
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}
