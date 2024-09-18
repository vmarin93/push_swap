/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:51:42 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/15 12:10:04 by vmarin           ###   ########.fr       */
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

int	*validate_from_array(char *argv1, int len)
{
	int		*input;
	int		i;
	char	**input_matrix;

	input_matrix = fill_input_matrix(argv1, len);
	input = malloc(sizeof(int) * len);
	if (input == NULL)
		exit(1);
	i = 0;
	while (i < len)
	{
		input[i] = do_int_conversion(input_matrix[i], input);
		i++;
	}
	free_input_matrix(input_matrix);
	return (input);
}

void	validate_input(int argc, char *argv[], t_Stack *stack_a)
{
	int	*input;
	int	len;
	int	duplicates;

	if (argc < 2)
		exit(1);
	if (argc == 2)
	{
		len = get_input_len(argv[1]);
		input = validate_from_array(argv[1], len);
	}
	else
	{
		len = argc - 1;
		input = get_input(argc, argv);
	}
	duplicates = check_for_duplicates(input, len);
	if (duplicates)
	{
		write(2, "Error\n", 6);
		free(input);
		exit (1);
	}
	fill_stack(input, len, stack_a);
	free(input);
}
