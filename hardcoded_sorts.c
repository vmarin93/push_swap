#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

Stack *sort_size_3(Stack *stack_a, int *op_count)
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
		write(1, "rra\n", 4);
		*op_count +=1;
		swap_top(stack_a);
		write(1, "sa\n", 3);
		*op_count +=1;
	}
	else if (top < middle && top > bottom)
	{
		rev_rotate_stack(stack_a);
		write(1, "rra\n", 4);
		*op_count +=1;
	}
	else if ((top > middle && top > bottom) && middle < bottom)
	{
		rotate_stack(stack_a);
		write(1, "ra\n", 3);
		*op_count +=1;
	}
	else if ((top > middle && top > bottom) && middle > bottom)
	{
		swap_top(stack_a);
		write(1, "sa\n", 3);
		*op_count +=1;
		rev_rotate_stack(stack_a);
		write(1, "rra\n", 4);
		*op_count +=1;
	}
	else if ((top > middle && top < bottom) && middle < bottom)
	{
		swap_top(stack_a);
		write(1, "sa\n", 3);
		*op_count +=1;
	}
	return (stack_a);
}

Stack *sort_size_4(Stack *stack_a, Stack *stack_b, int *op_count)
{
	int	smallest;
	int	steps_to_top;
	smallest = find_smallest(stack_a);
	steps_to_top= find_steps_to_top(stack_a, smallest);
	while (peek(stack_a) != smallest)
	{
		if (steps_to_top>= 2)
		{
			rotate_stack(stack_a);
			write(1, "ra\n", 3);
			*op_count +=1;
		}
		else
		{
			rev_rotate_stack(stack_a);
			write(1, "rra\n", 4);
			*op_count +=1;
		}
	}
	push(stack_b, pop(stack_a));
	write(1, "pb\n", 3);
	*op_count +=1;
	sort_size_3(stack_a, op_count);
	push(stack_a, pop(stack_b));
	write(1, "pa\n", 3);
	*op_count += 1;
	return(stack_a);
}

Stack *sort_size_5(Stack *stack_a, Stack *stack_b, int *op_count)
{
	int	smallest;
	int	largest;
	int	steps_to_top;

	smallest = find_smallest(stack_a);
	largest = find_largest(stack_a);
	steps_to_top = find_steps_to_top(stack_a, smallest);
	while(peek(stack_a) != smallest)
	{
		if (steps_to_top >= 2)
		{
			rotate_stack(stack_a);
			write(1, "ra\n", 3);
			*op_count +=1;
		}
		else
		{
			rev_rotate_stack(stack_a);
			write(1, "rra\n", 4);
			*op_count +=1;
		}
	}
	push(stack_b, pop(stack_a));
	write(1, "pb\n", 3);
	*op_count += 1;
	steps_to_top = find_steps_to_top(stack_a, largest);
	while(peek(stack_a) != largest)
	{
		if (steps_to_top >= 2)
		{
			rotate_stack(stack_a);
			write(1, "ra\n", 3);
			*op_count +=1;
		}
		else
		{
			rev_rotate_stack(stack_a);
			write(1, "rra\n", 4);
			*op_count +=1;
		}
	}
	push(stack_b, pop(stack_a));
	write(1, "pb\n", 3);
	*op_count += 1;
	sort_size_3(stack_a, op_count);
	push(stack_a, pop(stack_b));
	write(1, "pa\n", 3);
	*op_count += 1;
	if (peek(stack_a) > stack_a->numbers[stack_a->top - 1])
	{
		rotate_stack(stack_a);
		write(1, "ra\n", 3);
		*op_count +=1;
	}
	push(stack_a, pop(stack_b));
	write(1, "pa\n", 3);
	*op_count += 1;
	if (peek(stack_a) > stack_a->numbers[stack_a->top - 1])
	{
		rotate_stack(stack_a);
		write(1, "ra\n", 3);
		*op_count +=1;
	}
	return (stack_a);
}
