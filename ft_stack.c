#include "push_swap.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

Stack *create_stack(int size)
{
	if (size <= 0 || size > (int)(INT_MAX/ sizeof(int)))
		return (NULL);
	Stack *stack = malloc(sizeof(Stack));
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
	return stack;
}

void free_stack(Stack *stack)
{
	free(stack->numbers);
	free(stack);
}

int full_stack(const Stack *stack)
{
	if (stack->top == stack->size - 1)
		return (1);
	return (0);
}

int empty_stack(const Stack *stack)
{
	if (stack->top == -1)
		return (1);
	return (0);
}

long peek(const Stack *stack)
{
	if (empty_stack(stack))
		return (LONG_MAX);
	return (stack->numbers[stack->top]);
}

long push(Stack *stack, int number)
{
	if (full_stack(stack))
		return (LONG_MAX);
	stack->top++;
	stack->numbers[stack->top] = number;
	return (number);
}

long pop(Stack *stack)
{
	if (empty_stack(stack))
		return (LONG_MAX);
	stack->top--;
	return (stack->numbers[stack->top + 1]);
}

long swap_top(Stack *stack)
{
	if (stack->top < 1)
		return (LONG_MAX);
	int temp = stack->numbers[stack->top];
	stack->numbers[stack->top] = stack->numbers[stack->top - 1];
	stack->numbers[stack->top - 1] = temp;
	return (0);
}

long rotate_stack(Stack *stack)
{
	if (stack->top < 1)
		return (LONG_MAX);
	int temp_top = stack->numbers[stack->top];
	int i = stack->top;
	while (i > 0)
	{
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
	stack->numbers[i] = temp_top;
	return (0);
}

long rev_rotate_stack(Stack *stack)
{
	if (stack->top < 1)
		return (LONG_MAX);
	int temp_bottom = stack->numbers[0];
	int i = 0;
	while (i < stack->top)
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[i] = temp_bottom;
	return (0);
}
