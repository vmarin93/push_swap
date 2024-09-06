#include "push_swap.h"
#include <limits.h>

void	push_to_b(Stack *stack_a, Stack *stack_b, Operations *ops)
{
	long	average;
	while (stack_a->top >= 5)
	{
		average = (stack_sum(stack_a) / (stack_a->top + 1));
		if (peek(stack_a) > average)
		{
			rotate_stack(stack_a);
			register_ops("ra\n", ops);
		}
		else
		{
			push(stack_b, pop(stack_a));
			register_ops("pb\n", ops);
		}
	}
}

void fill_go_top_box(Stack *stack_a, Stack *stack_b, Box *go_top)
{
	int	i;

	go_top->total_steps = INT_MAX;
	i = stack_b->top;
	while (i >= 0)
	{
		go_top->current_pair = find_pair(stack_b->numbers[i], stack_a);
		if (go_top->current_pair != -1)
		{
			go_top->current_steps_a = find_steps_to_top(stack_a, go_top->current_pair);
			go_top->current_steps_b = find_steps_to_top(stack_b, stack_b->numbers[i]);
			if ((go_top->current_steps_a + go_top->current_steps_b) < go_top->total_steps)
			{
				go_top->value_top_a = go_top->current_pair;
				go_top->value_top_b = stack_b->numbers[i];
				go_top->steps_top_a = go_top->current_steps_a;
				go_top->steps_top_b = go_top->current_steps_b;
				go_top->total_steps = go_top->current_steps_a + go_top->current_steps_b;
			}
		}
		i--;
	}
}

void move_to_top_a(Stack *stack_a, Box *go_top, Operations *ops)
{
	while (peek(stack_a) != go_top->value_top_a)
	{
		if (go_top->steps_top_a > stack_a->top / 2)
		{
			rev_rotate_stack(stack_a);
			register_ops("rra\n", ops);
		}
		else
		{
			rotate_stack(stack_a);
			register_ops("ra\n", ops);
		}
	}
}

void move_to_top_b(Stack *stack_b, Box *go_top, Operations *ops)
{
	if (peek(stack_b) == go_top->value_top_b)
		return ;
	while (peek(stack_b) != go_top->value_top_b)
	{
		if (go_top->steps_top_b > stack_b->top / 2)
		{
			rev_rotate_stack(stack_b);
			register_ops("rrb\n", ops);
		}
		else
		{
			rotate_stack(stack_b);
			register_ops("rb\n", ops);
		}
	}
}

void	push_to_a(Stack *stack_a, Stack *stack_b, Operations *ops)
{
	Box	go_top;

	while (!empty_stack(stack_b))
	{
		fill_go_top_box(stack_a, stack_b, &go_top);
		move_to_top_a(stack_a, &go_top, ops);
		move_to_top_b(stack_b, &go_top, ops);
		push(stack_a, pop(stack_b));
		register_ops("pa\n", ops);
	}
}

void bring_largest_to_bottom(Stack *stack_a, Operations *ops)
{
	int	largest;
	int	steps_top;

	largest = find_largest(stack_a);
	steps_top = find_steps_to_top(stack_a, largest);
	while (stack_a->numbers[0] != largest)
	{
		if (steps_top < stack_a->top / 2)
		{
			rev_rotate_stack(stack_a);
			register_ops("rra\n", ops);
		}
		else
		{
			rotate_stack(stack_a);
			register_ops("ra\n", ops);
		}
	}
}

Stack *sort_large_stack(Stack *stack_a, Stack *stack_b, Operations *ops)
{
	push_to_b(stack_a, stack_b, ops);
	sort_size_5(stack_a, stack_b, ops);
	push_to_a(stack_a, stack_b, ops);
	bring_largest_to_bottom(stack_a, ops);
	return (stack_a);
}

Stack *sort_stack(Stack *stack_a, Stack *stack_b, Operations *ops)
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
	else
		sort_large_stack(stack_a, stack_b, ops);
	return (stack_a);
}
