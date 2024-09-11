/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:19:52 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/09 09:28:23 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotations(t_Stack *stack, t_Operations *ops, int index)
{
	if (index >= 2)
	{
		rotate_stack(stack);
		register_ops("ra\n", ops);
	}
	else
	{
		rev_rotate_stack(stack);
		register_ops("rra\n", ops);
	}
}

void	push_smallest(t_Stack *stack_a, t_Stack *stack_b, t_Operations *ops)
{
	int	smallest;
	int	index;

	smallest = find_smallest(stack_a);
	index = find_index(stack_a, smallest);
	while (peek(stack_a) != smallest)
		do_rotations(stack_a, ops, index);
	push(stack_b, pop(stack_a));
	register_ops("pb\n", ops);
}

void	push_largest(t_Stack *stack_a, t_Stack *stack_b, t_Operations *ops)
{
	int	largest;
	int	index;

	largest = find_largest(stack_a);
	index = find_index(stack_a, largest);
	while (peek(stack_a) != largest)
		do_rotations(stack_a, ops, index);
	push(stack_b, pop(stack_a));
	register_ops("pb\n", ops);
}

void	sort_size_5(t_Stack *stack_a, t_Stack *stack_b, t_Operations *ops)
{
	if (is_sorted(stack_a))
		return ;
	push_smallest(stack_a, stack_b, ops);
	push_largest(stack_a, stack_b, ops);
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
}
