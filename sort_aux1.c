/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:43:43 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/09 08:43:44 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	find_largest(t_Stack *stack)
{
	int	largest;
	int	i;

	if (!stack)
		return (-1);
	largest = stack->numbers[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->numbers[i] > largest)
			largest = stack->numbers[i];
		i++;
	}
	return (largest);
}

int	find_smallest(t_Stack *stack)
{
	int	smallest;
	int	i;

	if (!stack)
		return (-1);
	smallest = stack->numbers[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->numbers[i] < smallest)
			smallest = stack->numbers[i];
		i++;
	}
	return (smallest);
}

int	find_index(t_Stack *stack, int value)
{
	int	index;

	index = 0;
	while (index < stack->top)
	{
		if (stack->numbers[index] == value)
			return (index);
		index++;
	}
	return (index);
}

int	find_steps_to_top(t_Stack *stack, int value)
{
	int	steps;
	int	i;

	if (!stack)
		return (-1);
	steps = 0;
	if (peek(stack) == value)
		return (steps);
	i = stack->top;
	while (i >= 0)
	{
		if (stack->numbers[i] == value)
			break ;
		steps++;
		i--;
	}
	if (steps <= ((stack->top + 1) / 2))
		return (steps);
	else
		return (stack->top - steps + 1);
	return (-1);
}

long	find_pair(int value, t_Stack *stack)
{
	long	pair;
	long	i;
	long	smallest_diff;
	long	diff;

	if (!stack)
		return (LONG_MIN);
	pair = LONG_MAX;
	smallest_diff = LONG_MAX;
	i = 0;
	while (i <= stack->top)
	{
		if (stack->numbers[i] > value)
		{
			diff = (long)stack->numbers[i] - value;
			if (diff < smallest_diff)
			{
				smallest_diff = diff;
				pair = stack->numbers[i];
			}
		}
		i++;
	}
	return (pair);
}
