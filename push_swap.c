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

#include "push_swap.h"

void	create_stacks(t_Stack **stack_a, t_Stack **stack_b, int len)
{
	*stack_a = create_stack(len);
	if (*stack_a == NULL)
		exit(1);
	*stack_b = create_stack(len);
	if (*stack_b == NULL)
		exit(1);
}

void	free_stacks(t_Stack *stack_a, t_Stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char *argv[])
{
	t_Stack			*stack_a;
	t_Stack			*stack_b;
	t_Operations	ops;
	int				len;
	int				*input;

	ops.ops[0] = NULL;
	ops.count = 0;
	input = NULL;
	if (argc == 2)
		len = get_input_len(argv[1]);
	else
		len = argc - 1;
	validate_input(argc, argv, &input);
	create_stacks(&stack_a, &stack_b, len);
	fill_stack(input, len, stack_a);
	sort_stack(stack_a, stack_b, &ops);
	print_ops(&ops);
	free_ops(&ops);
	free(input);
	free_stacks(stack_a, stack_b);
	return (0);
}
