/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:51:42 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/11 13:02:43 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	do_int_conversion(char *arg, int *input)
{
	long	number;
	char	*endptr;

	number = ft_strtol(arg, &endptr);
	if (*endptr != '\0' || endptr == arg
		|| number == LONG_MAX || number == LONG_MIN)
	{
		write(2, "Error\n", 6);
		free(input);
		exit(1);
	}
	return (number);
}

int	*get_input(int argc, char *argv[])
{
	int	*input;
	int	i;

	input = malloc(sizeof(int) * (argc - 1));
	if (input == NULL)
		exit(1);
	i = 0;
	while (i < argc - 1)
	{
		input[i] = do_int_conversion(argv[i + 1], input);
		i++;
	}
	return (input);
}

int	check_for_duplicates(int *input, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (input[i] == input[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
}

void	validate_input(int argc, char *argv[], t_Stack *stack_a)
{
	int	*input;
	int	duplicates;

	if (argc < 2)
		exit(1);
	input = get_input(argc, argv);
	duplicates = check_for_duplicates(input, argc - 1);
	if (duplicates)
	{
		write(2, "Error\n", 6);
		free(input);
		exit (1);
	}
	fill_stack(input, argc - 1, stack_a);
	free(input);
}
