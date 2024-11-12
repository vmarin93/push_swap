/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:20:51 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/11 10:21:18 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

t_Stack	*create_stack(int size)
{
	t_Stack	*stack;

	if (size <= 0 || size > (int)(INT_MAX / sizeof(int)))
		return (NULL);
	stack = malloc(sizeof(t_Stack));
	if (stack == NULL)
		return (NULL);
	stack->numbers = malloc(sizeof(int) * size);
	if (stack->numbers == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->top = -1;
	stack->size = size;
	while (size >= 0)
	{
		size--;
		stack->numbers[size] = 0;
	}
	return (stack);
}

void	free_stack(t_Stack *stack)
{
	free(stack->numbers);
	stack->numbers = NULL;
	free(stack);
	stack = NULL;
}

int	full_stack(const t_Stack *stack)
{
	if (stack->top == stack->size - 1)
		return (1);
	return (0);
}

int	empty_stack(const t_Stack *stack)
{
	if (stack->top == -1)
		return (1);
	return (0);
}

long	peek(const t_Stack *stack)
{
	if (empty_stack(stack))
		return (LONG_MAX);
	return (stack->numbers[stack->top]);
}
