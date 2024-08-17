/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:09:19 by vmarin            #+#    #+#             */
/*   Updated: 2024/07/03 19:07:06 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Check for input. If no input, return the prompt to the user
// Sanitize the input. Make sure all arguments are integers and fit within the int type and 
	// that there are no duplicate integers in the input
// Build 2 stack structures, a and b.
// Store the input we get from the user at the command line in stack a
// implement the operations we are allowed to do for sorting the numbers:
	// sa (swap a): Swap the first 2 elements at the top of stack a.
	// 	Do nothing if there is only one or no elements.
	// sb (swap b): Swap the first 2 elements at the top of stack b.
	// 	Do nothing if there is only one or no elements.
	// ss : sa and sb at the same time.
	// pa (push a): Take the first element at the top of b and put it at the top of a.
	// 	Do nothing if b is empty.
	// pb (push b): Take the first element at the top of a and put it at the top of b.
	// 	Do nothing if a is empty.
	// ra (rotate a): Shift up all elements of stack a by 1.
	// 	The first element becomes the last one.
	// rb (rotate b): Shift up all elements of stack b by 1.
	// 	The first element becomes the last one.
	// rr : ra and rb at the same time.
	// rra (reverse rotate a): Shift down all elements of stack a by 1.
	// 	The last element becomes the first one.
	// rrb (reverse rotate b): Shift down all elements of stack b by 1.
	// 	The last element becomes the first one.
	// rrr : rra and rrb at the same time.
// create an array that is going to store all the operations we perform whilst sorting the input

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int is_sorted(Stack *stack)
{
	int	value;
	int	i;

	if (!stack)
		return (0);
	value = stack->numbers[stack->top];
	i = stack->size - 1;
	while(i > 0)
	{
		if (stack->numbers[i - 1] < value)
			return (0);
		value = stack->numbers[i - 1];
		i--;
	}
	return (1);
}

int is_rev_sorted(Stack *stack)
{
	int	value;
	int	i;

	if (!stack)
		return (0);
	value = stack->numbers[stack->top];
	i = stack->size - 1;
	while(i > 0)
	{
		if (stack->numbers[i - 1] > value)
			return (0);
		value = stack->numbers[i - 1];
		i--;
	}
	return (1);
}

int find_largest(Stack *stack)
{
	int	largest;
	int	i;

	if (!stack)
		return(-1);
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

int find_smallest(Stack *stack)
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

int find_steps_to_top(Stack *stack, int value)
{
	int	steps;
	int	i;

	if (!stack)
		return (-1);
	steps = 0;
	i = stack->top;
	while (i >= 0)
	{
		if (stack->numbers[i] == value)
			return(steps);
		steps++;
		i--;
	}
	return (-1);
}

int ft_sum(Stack *stack)
{
	int	sum;
	int	i;

	if (!stack)
		return (0);
	sum = 0;
	i = stack->top;
	while (i >= 0)
	{
		sum += stack->numbers[i];
		i--;
	}
	return(sum);
}

int find_pair(int value, Stack *stack)
{
	int	pair;
	int	i;
	int	perfect_pairing;
	int	smallest = INT_MAX;
	int	largest = INT_MIN;

	if (!stack)
		return (-1);
	pair = -1;
	perfect_pairing = INT_MAX;
	i = stack->top;
	while (i >= 0)
	{
		if (stack->numbers[i] < smallest)
			smallest = stack->numbers[i];
		if (stack->numbers[i] > largest)
			largest = stack->numbers[i];
		if (stack->numbers[i] > value && stack->numbers[i] - value < perfect_pairing)
		{
			pair = stack->numbers[i];
			perfect_pairing = stack->numbers[i] - value;
		}
		i--;
	}
	if (pair == -1 || (value > largest && smallest - value < perfect_pairing))
		pair = smallest;
	return (pair);
}

Stack *sort_stack(Stack *stack_a, Stack *stack_b, int *op_count)
{
	int	mean_value;
	int	*pairs;
	int	i;
	int	j;
	int	largest_stack_a;
	
	largest_stack_a = find_largest(stack_a);
	while (stack_a->top >= 5)
	{
		mean_value = (ft_sum(stack_a) / stack_a->top + 1);
		if (peek(stack_a) < mean_value)
		{
			push(stack_b, pop(stack_a));
			write(1, "pb\n", 3);
			*op_count += 1;
		}
		else
		{
			rotate_stack(stack_a);
			write(1, "ra\n", 3);
			*op_count += 1;
		}
	}
	sort_size_5(stack_a, stack_b, op_count);
	while (!empty_stack(stack_b))
	{
		int	steps_stack_a;
		int	steps_stack_b;
		int	value_top_a;
		int	value_top_b;
		int	total_steps;

		pairs = malloc(sizeof(int) * (2 * stack_b->top + 2));
		if (pairs == NULL)
			return (NULL);
		total_steps = INT_MAX;
		value_top_a = -1;
		value_top_b = -1;
		steps_stack_a = -1;
		steps_stack_b = -1;
		i = 0;
		j = stack_b->top;
		while (j >= 0)
		{
			pairs[i] = stack_b->numbers[j];
			i++;
			if (find_pair(stack_b->numbers[j], stack_a) != -1)
			{
				pairs[i] = find_pair(stack_b->numbers[j], stack_a);
			}
			i++;
			j--;
		}
		i = 0;
		while (i <= (2 * stack_b->top))
		{
			int	current_steps_b;
			int	current_steps_a;
			
			current_steps_b = find_steps_to_top(stack_b, pairs[i]);
			current_steps_a = find_steps_to_top(stack_a, pairs[i + 1]);
			if (current_steps_a < 0 || current_steps_b < 0)
			{
				i += 2;
				continue ;
			}
			if ((current_steps_b + current_steps_a) < total_steps)
			{
				value_top_a = pairs[i + 1];
				value_top_b = pairs[i];
				total_steps = current_steps_a + current_steps_b;
				steps_stack_a = current_steps_a;
				steps_stack_b = current_steps_b;
			}
			i += 2;
		}
		free(pairs);
		while (peek(stack_a) != value_top_a)
		{
			if (value_top_a == -1)
				break ;
			if (steps_stack_a <= stack_a->top / 2)
			{
				rotate_stack(stack_a);
				write(1, "ra\n", 3);
				*op_count += 1;
			}
			else
			{
				rev_rotate_stack(stack_a);
				write(1, "rra\n", 4);
				*op_count += 1;
			}
		}
		while (peek(stack_b) != value_top_b)
		{
			if (value_top_b == -1)
				break;
			if (steps_stack_b <= stack_b->top / 2)
			{
				rotate_stack(stack_b);
				write(1, "rb\n", 3);
				*op_count += 1;
			}
			else
			{
				rev_rotate_stack(stack_b);
				write(1, "rrb\n", 4);
				*op_count += 1;
			}
		}
		push(stack_a, pop(stack_b));
		write(1, "pa\n", 3);
		*op_count += 1;
		
	}
	while (stack_a->numbers[0] != largest_stack_a)
	{
		rotate_stack(stack_a);
		write(1, "ra1\n", 4);
		*op_count += 1;
	}
	return (stack_a);
}

int main(int argc, char *argv[])
{
	Stack *stack_a = create_stack(argc -1);
	if (stack_a == NULL)
		return (1);
	Stack *stack_b = create_stack(argc -1);
	if (stack_b == NULL)
		return (1);
	int	*input;
	char	*endptr;
	int	i;
	int	op_count;

	op_count = 0;
	if (argc < 2)
	{
		return (1);
	}
	input = malloc(sizeof(int) * (argc - 1)); 
	if (input == NULL) 
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		long	number;
		number = (ft_strtoi(argv[i + 1], &endptr));
		if (*endptr != '\0' || endptr == argv[i + 1] || number == LONG_MAX|| number == LONG_MIN)
		{
			write(2, "Error\n", 6);
			free(input);
			exit(1);
		}
		input[i] = (int)number;
		i++;
	}
	i = 0;
	while (i < argc - 2)
	{
		int	j;
		j = i + 1;
		while (j < argc - 1)
		{
			if (input[i] == input[j])
			{
				write(2, "Error\n", 6);
				free(input);
				exit(1);
			}
			j++;
		}
		i++;
	}
	i = argc - 2;
	while (i >= 0)
	{
		push(stack_a, input[i]);
		i--;
	}
	free(input);
	sort_stack(stack_a, stack_b, &op_count);
	printf("\n");
	printf("Stack sorted using %d operations", op_count);
	printf("\n");
	i = stack_a->size - 1;
	while (i >= 0)
	{
		printf("%d ", stack_a->numbers[i]);
		i--;
	}
	printf("\n");
	free_stack(stack_a);
	free_stack(stack_b);
}
