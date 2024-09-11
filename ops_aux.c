/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@42london.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:41:21 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/09 08:42:21 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	squash_ops(char *op, t_Operations *ops, int *squashed, char *new_op)
{
	char	*prev_op;

	prev_op = ops->ops[ops->count - 1];
	*squashed = 0;
	if (ft_strcmp(prev_op, "rrb\n") == 0 && ft_strcmp(op, "rra\n") == 0)
		new_op = "rrr\n";
	else if (ft_strcmp(prev_op, "rra\n") == 0 && ft_strcmp(op, "rrb\n") == 0)
		new_op = "rrr\n";
	else if (ft_strcmp(prev_op, "ra\n") == 0 && ft_strcmp(op, "rb\n") == 0)
		new_op = "rr\n";
	else if (ft_strcmp(prev_op, "rb\n") == 0 && ft_strcmp(op, "ra\n") == 0)
		new_op = "rr\n";
	if (new_op)
	{
		free(prev_op);
		ops->ops[ops->count - 1] = ft_strdup(new_op);
		if (ops->ops[ops->count - 1] == NULL)
			exit(1);
		*squashed = 1;
	}
}

void	register_ops(char *op, t_Operations *ops)
{
	int		squashed;
	char	*new_op;

	new_op = NULL;
	squashed = 0;
	if (op == NULL || ops == NULL)
		exit(1);
	if (ops->count >= 14999)
		exit(1);
	if (ops->count > 0)
	{
		squash_ops(op, ops, &squashed, new_op);
	}
	if (!squashed)
	{
		ops->ops[ops->count] = ft_strdup(op);
		if (ops->ops[ops->count] == NULL)
			exit(1);
		ops->count++;
	}
}

void	print_ops(t_Operations *ops)
{
	int	i;

	i = 0;
	while (i < ops->count)
	{
		write(1, ops->ops[i], ft_strlen(ops->ops[i]));
		i++;
	}
}

void	free_ops(t_Operations *ops)
{
	int	i;

	i = 0;
	while (i < ops->count)
	{
		free(ops->ops[i]);
		ops->ops[i] = NULL;
		i++;
	}
	ops->count = 0;
}
