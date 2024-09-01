#include "tests.h"
#include "../push_swap.h"
#include <stdlib.h>

void test_find_smallest()
{
	Stack	*test_stack = create_stack(10);
	if (test_stack == NULL)
		return;
	int	smallest;

	test_stack->numbers[0] = 2;
	test_stack->numbers[1] = 7;
	test_stack->numbers[2] = 4;
	test_stack->numbers[3] = 13;
	test_stack->numbers[4] = 22;
	test_stack->numbers[5] = 39;
	test_stack->numbers[6] = 40;
	test_stack->numbers[7] = 99;
	test_stack->numbers[8] = 34;
	test_stack->numbers[9] = 76;

	smallest = find_smallest(test_stack);
	ASSERT(smallest == 2, "the function did not return the smallest element in the stack");
	TEST_PASS("test_find_smallest");
}
