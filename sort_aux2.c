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
#include <limits.h>

int	fill_go_top_box(t_Stack *stack_a, t_Stack *stack_b, t_Box *go_top)
{
	int	i;

	go_top->value_top_a = 0;
	go_top->value_top_b = 0;
	go_top->steps_top_a = 0;
	go_top->steps_top_b = 0;
	go_top->total_steps = INT_MAX;
	i = stack_b->top;
	while (i >= 0)
	{
		go_top->current_pair = find_pair(stack_b->numbers[i], stack_a);
		if (go_top->current_pair != LONG_MAX)
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
	i = stack_a->top;
	return (0);
}

void	m(t_Stack *stack_a, t_Stack *stack_b, t_Box *go_top, t_Operations *ops)
{
	while (go_top->steps_top_a && go_top->steps_top_b)
	{
		if ((stack_a->top / 2) <= go_top->i_a && (stack_b->top / 2 <= go_top->i_b))
		{
			rotate_stack(stack_a);
			rotate_stack(stack_b);
			register_ops("rr\n", ops);
			go_top->steps_top_a--;
			go_top->steps_top_b--;
		}
		else if ((stack_a->top / 2) > go_top->i_a && (stack_b->top / 2 >go_top->i_b))
		{
			rev_rotate_stack(stack_a);
			rev_rotate_stack(stack_b);
			register_ops("rrr\n", ops);
			go_top->steps_top_a--;
			go_top->steps_top_b--;
		}
		else
			return ;
	}
}

void	move_to_top_a(t_Stack *stack_a, t_Box *go_top, t_Operations *ops)
{
	while (go_top->steps_top_a)
	{
		if ((stack_a->top / 2) <= go_top->i_a)
		{
			rotate_stack(stack_a);
			register_ops("ra\n", ops);
			go_top->steps_top_a--;
		}
		else
		{
			rev_rotate_stack(stack_a);
			register_ops("rra\n", ops);
			go_top->steps_top_a--;
		}
	}
}

void	move_to_top_b(t_Stack *stack_b, t_Box *go_top, t_Operations *ops)
{
	while (go_top->steps_top_b)
	{
		if ((stack_b->top / 2) <= go_top->i_b)
		{
			rotate_stack(stack_b);
			register_ops("rb\n", ops);
			go_top->steps_top_b--;
		}
		else
		{
			rev_rotate_stack(stack_b);
			register_ops("rrb\n", ops);
			go_top->steps_top_b--;
		}
	}
}

long	get_average(t_Stack *stack) 
{
	long	sum = 0;
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		sum += stack->numbers[i];
		i++;
	}
	return (sum / (stack->top + 1));
}
