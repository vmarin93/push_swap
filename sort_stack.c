#include "push_swap.h"

//Stack *sort_large_stack(Stack *stack_a, Stack *stack_b, char **ops)
//{
//	return (stack_a);
//}

Stack *sort_stack(Stack *stack_a, Stack *stack_b, char **ops)
{
	if (is_sorted(stack_a))
		return (stack_a);
	else if (stack_a->top == 0)
		return(stack_a);
	else if (stack_a->top == 1)
	{
		if (stack_a->numbers[stack_a->top] > stack_a->numbers[0])
		{
			swap_top(stack_a);
			register_ops("sa\n", ops);
		}
	}
	else if (stack_a->top == 2)
		sort_size_3(stack_a, ops);
	else if (stack_a->top == 3)
		sort_size_4(stack_a, stack_b, ops);
	else if (stack_a->top == 4)
		sort_size_5(stack_a, stack_b, ops);
//	else
//		sort_large_stack(stack_a, stack_b, ops);
	return (stack_a);
}
