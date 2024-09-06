#include "push_swap.h"
#include <string.h>

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

long stack_sum(Stack *stack)
{
	long	sum;
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

	if (!stack)
		return (-1);
	pair = -1;
	perfect_pairing = INT_MAX;
	i = stack->top;
	while (i >= 0)
	{
		if (stack->numbers[i] > value && ((stack->numbers[i] - value) < perfect_pairing))
		{
			pair = stack->numbers[i];
			perfect_pairing = stack->numbers[i] - value;
		}
		i--;
	}
	return (pair);
}

int ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char	*dup;
	int	i;

	if (str == NULL)
		return (NULL);
	dup = malloc(ft_strlen(str) + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	squash_ops(char *op, Operations *ops, int *squashed)
{
	char	*prev_op = ops->ops[ops->count - 1];
	char	*new_op = NULL;

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

void register_ops(char *op, Operations *ops)
{
	int	squashed;

	squashed = 0;
	if (op == NULL || ops == NULL)
		exit(1);
	if (ops->count >= 14999)
		exit(1);
	if (ops->count > 0)
	{
		squash_ops(op, ops, &squashed);
	}
	if (!squashed)
	{
		ops->ops[ops->count] = ft_strdup(op);
		if (ops->ops[ops->count] == NULL)
			exit(1);
		ops->count++;
	}
}

void free_ops(Operations *ops)
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

int ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}
