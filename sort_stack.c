/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:33:19 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/09 09:34:49 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_Stack *stack_a, t_Stack *stack_b, t_Operations *ops)
{
	long	average;

	average = (stack_sum(stack_a) / (stack_a->top + 1));
	while (stack_a->top >= 5)
	{
		if (peek(stack_a) > average)
		{
			rotate_stack(stack_a);
			register_ops("ra\n", ops);
		}
		else
		{
			push(stack_b, pop(stack_a));
			register_ops("pb\n", ops);
			average = (stack_sum(stack_a) / (stack_a->top + 1));
		}
	}
}

void	push_to_a(t_Stack *stack_a, t_Stack *stack_b, t_Operations *ops)
{
	t_Box	go_top;

	while (!empty_stack(stack_b))
	{
		fill_go_top_box(stack_a, stack_b, &go_top);
		move_to_top_a(stack_a, &go_top, ops);
		move_to_top_b(stack_b, &go_top, ops);
		push(stack_a, pop(stack_b));
		register_ops("pa\n", ops);
	}
}

void	bring_largest_to_bottom(t_Stack *stack_a, t_Operations *ops)
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

t_Stack	*sort_large_stack(t_Stack *stack_a, t_Stack *stack_b, t_Operations *ops)
{
	push_to_b(stack_a, stack_b, ops);
	sort_size_5(stack_a, stack_b, ops);
	push_to_a(stack_a, stack_b, ops);
	bring_largest_to_bottom(stack_a, ops);
	return (stack_a);
}

t_Stack	*sort_stack(t_Stack *stack_a, t_Stack *stack_b, t_Operations *ops)
{
	if (is_sorted(stack_a))
		return (stack_a);
	else if (stack_a->top == 0)
		return (stack_a);
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
