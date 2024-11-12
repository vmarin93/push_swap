#include "tests.h"
#include "../push_swap.h"
#include <stdlib.h>
#include <string.h>

void test_sort_size_2()
{
	t_Stack	*stack_a = create_stack(2);
	t_Stack	*stack_b = create_stack(2);
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	t_Operations ops = {0};

	stack_a->numbers[0] = -43;
	stack_a->numbers[1] = 42;
	stack_a->top = 1;
	sort_stack(stack_a, stack_b, &ops);
	ASSERT(stack_a->numbers[0] == 42, "the 2 element stack was not sorted");
	ASSERT(stack_a->numbers[1] == -43, "the 2 element stack was not sorted");
	ASSERT(ops.count == 1, "it took more than 1 operation to sort a stack of 2 elements");
	TEST_PASS("test_sort_size_2");

	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}

void test_sort_size_3()
{
	t_Stack	*stack_a = create_stack(3);
	t_Stack	*stack_b = create_stack(3);
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	t_Operations ops = {0};
	
	stack_a->numbers[0] = 75;
	stack_a->numbers[1] = -89;
	stack_a->numbers[2] = 56;
	stack_a->top = 2;
	sort_stack(stack_a, stack_b, &ops);
	ASSERT(stack_a->numbers[0] == 75, "the 3 element stack was not sorted");
	ASSERT(stack_a->numbers[1] == 56, "the 3 element stack was not sorted");
	ASSERT(stack_a->numbers[2] == -89, "the 3 element stack was not sorted");
	ASSERT(ops.count == 1, "too many ops to sort stack. should be one op only");
	TEST_PASS("test_sort_size_3");
	
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}

void test_sort_size_4()
{
	t_Stack	*stack_a = create_stack(4);
	t_Stack	*stack_b = create_stack(4);
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	;
	t_Operations ops = {0};
	int	i;
	int	numbers[4] = {42, -67, -31, 84};
	int	sorted_numbers[4] = {84, 42, -31, -67};
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
	ASSERT(ops.count <= 5, "stack was not sorted in the most optimal way");
	TEST_PASS("test_sort_size_4");
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}

void test_sort_size_5()
{
	t_Stack	*stack_a = create_stack(5);
	t_Stack	*stack_b = create_stack(5);
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	t_Operations ops = {0};
	int	i;
	int	numbers[5] = {-43, 89, -54, 12, 32};
	int	sorted_numbers[5] = {89, 32, 12, -43, -54};
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
	ASSERT(ops.count <= 10, "stack was not sorted in the most optimal way");
	TEST_PASS("test_sort_size_5");
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}

void	test_bring_largest_to_bottom()
{
	t_Stack *stack_a = create_stack(5);
	t_Stack *stack_b = create_stack(5);
	
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	t_Operations ops = {0};
	
	int numbers[] = {1, -2, 5, -3, -4};
	memcpy(stack_a->numbers, numbers, sizeof(numbers));
	stack_a->top = 4;
	
	bring_largest_to_bottom(stack_a, &ops);
	
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}

void test_push_to_b()
{
	t_Stack	*stack_a = create_stack(12);
	t_Stack	*stack_b = create_stack(12);
	if (stack_a == NULL || stack_b == NULL)
		return;
	t_Operations	ops = {0};
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
	t_Box	go_top;
	t_Stack	*stack_a = create_stack(19);
	t_Stack	*stack_b = create_stack(1);
	if (stack_a == NULL || stack_b == NULL)
		return ;
	int	numbers_a[19] = {-337, 88, 148, 175, 209, 262, 283, 299, 306, 317, 325, 338, 342, 347, 401, 409, 424, 444, 496};
	int	numbers_b[1] = {-75};
	fill_stack(numbers_a, 19, stack_a);
	stack_a->top = 18;
	fill_stack(numbers_b, 1, stack_b);
	stack_b->top = 0;

	fill_go_top_box(stack_a, stack_b, &go_top);
	ASSERT(go_top.value_top_a == 88, "incorrect value_top_a");
	printf("value_top_a[%d]", go_top.value_top_a);
	ASSERT(go_top.value_top_b == -75, "incorrect value_top_b");
	printf("steps_top_a[%d]", go_top.steps_top_a);
	ASSERT(go_top.steps_top_a == 1, "incorrect steps_top_a");
	ASSERT(go_top.steps_top_b == 0, "incorrect steps_top_b");
	TEST_PASS("test_fill_go_top_box");
	free_stack(stack_a);
	free_stack(stack_b);
}

void test_move_to_top_a()
{
	t_Box	go_top;
	t_Operations	ops = {0};
	t_Stack	*stack_a = create_stack(5);
	if (stack_a == NULL)
		return ;
	int	numbers[5] = {64, 88, -91, 78, 65};
	fill_stack(numbers, 5, stack_a);
	go_top.value_top_a = -91;
	go_top.steps_top_a = 2;
	go_top.i_a = stack_a->size - 3;

	move_to_top_a(stack_a, &go_top, &ops);
	ASSERT(peek(stack_a) == -91, "value was not moved to the top of stack a");
	TEST_PASS("test_move_to_top_a");
	free_stack(stack_a);
	free_ops(&ops);
}

void test_move_to_top_b()
{
	t_Box	go_top;
	t_Operations	ops = {0};
	t_Stack	*stack_b = create_stack(7);
	if (stack_b == NULL)
		return ;
	int	numbers[7] = {15, 9, 27, 33, 12, -43, 75};
	fill_stack(numbers, 7, stack_b);
	go_top.value_top_b = -43;
	go_top.steps_top_b = 2;
	go_top.i_b = stack_b->size - 5;

	move_to_top_b(stack_b, &go_top, &ops);
	ASSERT(peek(stack_b) == -43, "value was not moved to the top of stack b");
	TEST_PASS("test_move_to_top_b");
	free_stack(stack_b);
	free_ops(&ops);
}

void test_sort_stack()
{
	int	i;
	t_Stack	*stack_a = create_stack(100);
	t_Stack	*stack_b = create_stack(100);
	if (stack_a == NULL || stack_b == NULL)
		return ;
	t_Operations	ops = {0};
	int	numbers[100] = {-337, 344, -75, -296, 92, 135, 237, -365, -208, 317, -498, -364, 409, 283, -451, 401, -367, -5, 178, 424, -391, -202, 81, 147, -325, -463, 338, 10, 222, -149, -470, 116, -323, -278, -168, 325, -47, -258, -205, -64, -405, -464, 342, -228, -86, -318, 206, 347, -214, -222, 290, 298, -392, 88, -30, -15, 5, 148, -233, 175, 209, -241, -85, -448, 37, -395, -195, -253, -220, -243, -400, -33, -217, -4, -139, -131, 39, -70, 336, 262, -22, 130, -285, 306, -473, -313, -438, 191, 496, 137, 161, 299, 25, -429, 67, 121, 444, -335, 118, 198};
	int	sorted_numbers[100] = {-498, -473, -470, -464, -463, -451, -448, -438, -429, -400, -395, -392, -391, -367, -365, -364, -335, -325, -323, -318, -313, -296, -285, -278, -258, -253, -243, -241, -233, -228, -222, -220, -217, -214, -208, -205, -202, -195, -168, -149, -139, -131, -86, -85, -75, -70, -64, -47, -33, -30, -22, -15, -5, -4, 5, 10, 25, 37, 39, 67, 81, 88, 92, 116, 118, 121, 130, 135, 137, 147, 148, 161, 175, 178, 191, 198, 206, 209, 222, 237, 262, 283, 290, 298, 299, 306, 317, 325, 336, 338, 342, 344, 347, 401, 409, 424, 444, 496};
	fill_stack(numbers, 100, stack_a);

	sort_stack(stack_a, stack_b, &ops);
	i = 0;
	while (i < 100)
	{
		if (stack_a->numbers[i] != sorted_numbers[i])
			break;
		i++;
	}
	ASSERT(i == 99, "the stack was not sorted");
	TEST_PASS("test_sort_stack");
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
}
