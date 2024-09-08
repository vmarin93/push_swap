#include "push_swap.h"
#include <sys/types.h>
#include <unistd.h>

Stack *sort_size_3(Stack *stack_a, Operations *ops)
{
	int	top;
	int	bottom;
	int	middle;

	if (is_sorted(stack_a))
		return (stack_a);
	top = stack_a->numbers[stack_a->top];
	bottom = stack_a->numbers[0];
	middle = stack_a->numbers[stack_a->top - 1];
	if ((top < middle && top < bottom) && middle > bottom)
	{
		rev_rotate_stack(stack_a);
		register_ops("rra\n", ops);
		swap_top(stack_a);
		register_ops("sa\n", ops);
	}
	else if (top < middle && top > bottom)
	{
		rev_rotate_stack(stack_a);
		register_ops("rra\n", ops);
	}
	else if ((top > middle && top > bottom) && middle < bottom)
	{
		rotate_stack(stack_a);
		register_ops("ra\n", ops);
	}
	else if ((top > middle && top > bottom) && middle > bottom)
	{
		swap_top(stack_a);
		register_ops("sa\n", ops);
		rev_rotate_stack(stack_a);
		register_ops("rra\n", ops);
	}
	else if ((top > middle && top < bottom) && middle < bottom)
	{
		swap_top(stack_a);
		register_ops("sa\n", ops);
	}
	return (stack_a);
}

Stack *sort_size_4(Stack *stack_a, Stack *stack_b, Operations *ops)
{
	int	smallest;
	int	index;

	smallest = find_smallest(stack_a);
	index = find_index(stack_a, smallest);
	while (peek(stack_a) != smallest)
	{
		if (index >= 2)
		{
			rotate_stack(stack_a);
			register_ops("ra\n", ops);
		}
		else
		{
			rev_rotate_stack(stack_a);
			register_ops("rra\n", ops);
		}
	}
	push(stack_b, pop(stack_a));
	register_ops("pb\n", ops);
	sort_size_3(stack_a, ops);
	push(stack_a, pop(stack_b));
	register_ops("pa\n", ops);
	return(stack_a);
}

Stack *sort_size_5(Stack *stack_a, Stack *stack_b, Operations *ops)
{
	int	smallest;
	int	largest;
	int	index;

	smallest = find_smallest(stack_a);
	largest = find_largest(stack_a);
	index = find_index(stack_a, smallest);
	while(peek(stack_a) != smallest)
	{
		if (index >= 2)
		{
			rotate_stack(stack_a);
			register_ops("ra\n", ops);
		}
		else
		{
			rev_rotate_stack(stack_a);
			register_ops("rra\n", ops);
		}
	}
	push(stack_b, pop(stack_a));
	register_ops("pb\n", ops);
	index = find_index(stack_a, largest);
	while(peek(stack_a) != largest)
	{
		if (index >= 2)
		{
			rotate_stack(stack_a);
			register_ops("ra\n", ops);
		}
		else
		{
			rev_rotate_stack(stack_a);
			register_ops("rra\n", ops);
		}
	}
	push(stack_b, pop(stack_a));
	register_ops("pb\n", ops);
	sort_size_3(stack_a, ops);
	push(stack_a, pop(stack_b));
	register_ops("pa\n", ops);
	if (peek(stack_a) > stack_a->numbers[stack_a->top - 1])
	{
		rotate_stack(stack_a);
		register_ops("ra\n", ops);
	}
	push(stack_a, pop(stack_b));
	register_ops("pa\n", ops);
	if (peek(stack_a) > stack_a->numbers[stack_a->top - 1])
	{
		rotate_stack(stack_a);
		register_ops("ra\n", ops);
	}
	return (stack_a);
}
