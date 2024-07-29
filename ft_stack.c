#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

Stack *create_stack(int size)
{
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

int full_stack(Stack *stack)
{
	if (stack->top == stack->size - 1)
		return (1);
	return (0);
}

int empty_stack(Stack *stack)
{
	if (stack->top == -1)
		return (1);
	return (0);
}

int peek(Stack *stack)
{
	if (empty_stack(stack))
		return (-1);
	return (stack->numbers[stack->top]);
	stack->top++;
}

int push(Stack *stack, int number)
{
	if (full_stack(stack))
		return (0);
	stack->top++;
	stack->numbers[stack->top] = number;
	return (number);
}

int pop(Stack *stack)
{
	if (empty_stack(stack))
		return (-1);
	stack->top--;
	return (stack->numbers[stack->top + 1]);
}
