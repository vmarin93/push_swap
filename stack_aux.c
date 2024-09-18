/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:35:02 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/15 08:35:29 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_Stack *stack)
{
	int	value;
	int	i;

	if (!stack)
		return (0);
	value = stack->numbers[stack->top];
	i = stack->size - 1;
	while (i > 0)
	{
		if (stack->numbers[i - 1] < value)
			return (0);
		value = stack->numbers[i - 1];
		i--;
	}
	return (1);
}

long	stack_sum(t_Stack *stack)
{
	long	sum;
	int		i;

	if (!stack)
		return (0);
	sum = 0;
	i = stack->top;
	while (i >= 0)
	{
		sum += stack->numbers[i];
		i--;
	}
	return (sum);
}

void	fill_stack(int *input, int len, t_Stack *stack_a)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		push(stack_a, input[i]);
		i--;
	}
	if (stack_a == NULL)
	{
		write(2, "Error\n", 6);
		free(input);
		exit(1);
	}
}
