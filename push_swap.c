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

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

	if (argc < 2)
	{
		return (1);
	}
	input = malloc(sizeof(int) * (argc - 1));
	if (input == NULL)
	{
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		long	number;
		number = (ft_strtoi(argv[i], &endptr));
		if (*endptr != '\0'|| endptr == argv[i] || number == LONG_MAX|| number == LONG_MIN)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		input[i] = number;
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		int	j;
		j = i + 1;
		while (j < argc)
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
	i = argc - 1;
}
