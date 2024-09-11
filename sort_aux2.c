/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:45:59 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/09 08:46:40 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_go_top_box(t_Stack *stack_a, t_Stack *stack_b, t_Box *go_top)
{
	int	i;

	go_top->total_steps = INT_MAX;
	i = stack_b->top;
	while (i >= 0)
	{
		go_top->current_pair = find_pair(stack_b->numbers[i], stack_a);
		if (go_top->current_pair != -1)
		{
			go_top->curr_a = find_steps_to_top(stack_a, go_top->current_pair);
			go_top->curr_b = find_steps_to_top(stack_b, stack_b->numbers[i]);
			if ((go_top->curr_a + go_top->curr_b) < go_top->total_steps)
			{
				go_top->value_top_a = go_top->current_pair;
				go_top->value_top_b = stack_b->numbers[i];
				go_top->steps_top_a = go_top->curr_a;
				go_top->steps_top_b = go_top->curr_b;
				go_top->total_steps = go_top->curr_a + go_top->curr_b;
			}
		}
		i--;
	}
}

void	move_to_top_a(t_Stack *stack_a, t_Box *go_top, t_Operations *ops)
{
	int	value_index;

	value_index = find_index(stack_a, go_top->value_top_a);
	if ((stack_a->top / 2) <= value_index)
	{
		while (go_top->steps_top_a)
		{
			rotate_stack(stack_a);
			register_ops("ra\n", ops);
			go_top->steps_top_a--;
		}
	}
	else if ((stack_a->top / 2) > value_index)
	{
		while (go_top->steps_top_a)
		{
			rev_rotate_stack(stack_a);
			register_ops("rra\n", ops);
			go_top->steps_top_a--;
		}
	}
}

void	move_to_top_b(t_Stack *stack_b, t_Box *go_top, t_Operations *ops)
{
	int	value_index;

	value_index = find_index(stack_b, go_top->value_top_b);
	if ((stack_b->top / 2) <= value_index)
	{
		while (go_top->steps_top_b)
		{
			rotate_stack(stack_b);
			register_ops("rb\n", ops);
			go_top->steps_top_b--;
		}
	}
	else if ((stack_b->top / 2) > value_index)
	{
		while (go_top->steps_top_b)
		{
			rev_rotate_stack(stack_b);
			register_ops("rrb\n", ops);
			go_top->steps_top_b--;
		}
	}
}
