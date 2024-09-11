/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:28:52 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/09 08:29:51 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	push(t_Stack *stack, int number)
{
	if (full_stack(stack))
		return (LONG_MAX);
	stack->top++;
	stack->numbers[stack->top] = number;
	return (number);
}

long	pop(t_Stack *stack)
{
	if (empty_stack(stack))
		return (LONG_MAX);
	stack->top--;
	return (stack->numbers[stack->top + 1]);
}

long	swap_top(t_Stack *stack)
{
	int	temp;

	if (stack->top < 1)
		return (LONG_MAX);
	temp = stack->numbers[stack->top];
	stack->numbers[stack->top] = stack->numbers[stack->top - 1];
	stack->numbers[stack->top - 1] = temp;
	return (0);
}

long	rotate_stack(t_Stack *stack)
{
	int	temp_top;
	int	i;

	if (stack->top < 1)
		return (LONG_MAX);
	temp_top = stack->numbers[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
	stack->numbers[i] = temp_top;
	return (0);
}

long	rev_rotate_stack(t_Stack *stack)
{
	int	temp_bottom;
	int	i;

	if (stack->top < 1)
		return (LONG_MAX);
	temp_bottom = stack->numbers[0];
	i = 0;
	while (i < stack->top)
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[i] = temp_bottom;
	return (0);
}
