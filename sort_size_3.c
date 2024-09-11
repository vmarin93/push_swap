/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:55:18 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/09 09:05:51 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_case(t_Stack *stack_a, t_Operations *ops)
{
	rev_rotate_stack(stack_a);
	register_ops("rra\n", ops);
	swap_top(stack_a);
	register_ops("sa\n", ops);
}

void	second_case(t_Stack *stack_a, t_Operations *ops)
{
	rev_rotate_stack(stack_a);
	register_ops("rra\n", ops);
}

void	third_case(t_Stack *stack_a, t_Operations *ops)
{
	rotate_stack(stack_a);
	register_ops("ra\n", ops);
}

void	fourth_case(t_Stack *stack_a, t_Operations *ops)
{
	swap_top(stack_a);
	register_ops("sa\n", ops);
	rev_rotate_stack(stack_a);
	register_ops("rra\n", ops);
}

void	sort_size_3(t_Stack *stack_a, t_Operations *ops)
{
	int	top;
	int	bottom;
	int	middle;

	if (is_sorted(stack_a))
		return ;
	top = stack_a->numbers[stack_a->top];
	bottom = stack_a->numbers[0];
	middle = stack_a->numbers[stack_a->top - 1];
	if ((top < middle && top < bottom) && middle > bottom)
		first_case(stack_a, ops);
	else if (top < middle && top > bottom)
		second_case(stack_a, ops);
	else if ((top > middle && top > bottom) && middle < bottom)
		third_case(stack_a, ops);
	else if ((top > middle && top > bottom) && middle > bottom)
		fourth_case(stack_a, ops);
	else if ((top > middle && top < bottom) && middle < bottom)
	{
		swap_top(stack_a);
		register_ops("sa\n", ops);
	}
}
