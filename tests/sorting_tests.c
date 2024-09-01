#include "tests.h"
#include "../push_swap.h"
#include <stdlib.h>

void test_sort_size_2()
{
	Stack	*stack_a = create_stack(2);
	Stack	*stack_b = create_stack(2);
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	char	*ops[15000] = {NULL};

	stack_a->numbers[0] = 42;
	stack_a->numbers[1] = 43;
	stack_a->top = 1;
	sort_stack(stack_a, stack_b, ops);
	ASSERT(stack_a->numbers[0] == 43, "the 2 element stack was not sorted");
	ASSERT(stack_a->numbers[1] == 42, "the 2 element stack was not sorted");
	ASSERT(ops[1] == NULL, "it took more than 1 operation to sort a stack of 2 elements");
	TEST_PASS("test_sort_size_2");

	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(ops);
}

void test_sort_size_3()
{
	Stack	*stack_a = create_stack(3);
	Stack	*stack_b = create_stack(3);
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	char	*ops[15000] = {NULL};
	int	op_count = 0;
	
	stack_a->numbers[0] = 75;
	stack_a->numbers[1] = 56;
	stack_a->numbers[2] = 89;
	stack_a->top = 2;
	sort_stack(stack_a, stack_b, ops);
	ASSERT(stack_a->numbers[0] == 89, "the 3 element stack was not sorted");
	ASSERT(stack_a->numbers[1] == 75, "the 3 element stack was not sorted");
	ASSERT(stack_a->numbers[2] == 56, "the 3 element stack was not sorted");
	while (ops[op_count] != NULL)
	{
		op_count++;
	}
	ASSERT(op_count == 1, "too many ops to sort stack. should be one op only");
	TEST_PASS("test_sort_size_3");
	
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(ops);
}

//void test_sort_size_4()
//{
//	Stack	*stack_a = create_stack(4);
//	Stack	*stack_b = create_stack(4);
//	if (stack_a == NULL || stack_b == NULL)
//		exit(1);
//	char	*ops[15000] = {NULL};
//	int	op_count = 0;
//	
//	stack_a->numbers[0] = 42;
//	stack_a->numbers[1] = 67;
//	stack_a->numbers[2] = 31;
//	stack_a->numbers[3] = 84;
//	stack_a->top = 3;
//	free_stack(stack_a);
//	free_stack(stack_b);
//	free_ops(ops);
//}
