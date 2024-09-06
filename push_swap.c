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

int main(int argc, char *argv[])
{
	Stack	*stack_a;
	Stack	*stack_b;
	Operations	ops = {0};

	stack_a = create_stack(argc - 1);
	if (stack_a == NULL)
		return (1);
	stack_b = create_stack(argc-1);
	if (stack_b == NULL)
		return (1);
	validate_input(argc, argv, stack_a);
	sort_stack(stack_a, stack_b, &ops);
	int	i = 0;
	printf("\n");
	while (i < ops.count)
	{
		printf("%s", ops.ops[i]);
		i++;
	}
	printf("\nOp Count: %d \n", ops.count);
	i = stack_a->top;
	while (i >= 0)
	{
		printf("%d ", stack_a->numbers[i]);
		i--;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	free_ops(&ops);
	return (0);
}
