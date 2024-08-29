#include "push_swap.h"

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

long ft_sum(Stack *stack)
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


int ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void register_ops(const char *op, char **ops)
{
	int	i;
	int	j;
	
	i = 0;
	while(ops[i] != NULL)
		i++;
	if (i == 15000)
		exit(1);
	j = 0;
	while (op[j] != '\0')
	{
		ops[i][j] = op[j];
		j++;
	}
	ops[i][j] = '\0';
}

Stack *sort_stack(Stack *stack_a, Stack *stack_b, char **ops) 
{
	long	mean_value;
	int	*pairs;
	int	i;
	int	j;
	int	largest_stack_a;
	
	if (is_sorted(stack_a))
		return (stack_a);
	else if (stack_a->top == 2)
		sort_size_3(stack_a, ops);
	else if (stack_a->top == 3)
		sort_size_4(stack_a, stack_b, ops);
	else if (stack_a->top == 4)
		sort_size_5(stack_a, stack_b, ops);
	largest_stack_a = find_largest(stack_a);
	while (stack_a->top >= 5)
	{
		mean_value = (ft_sum(stack_a) / stack_a->top + 1);
		if (peek(stack_a) > mean_value)
		{
			rotate_stack(stack_a);
			register_ops("ra\n", ops);
		}
		else
		{
			push(stack_b, pop(stack_a));
			register_ops("pb\n", ops);
		}
	}
	sort_size_5(stack_a, stack_b, ops);
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
			if (steps_stack_a > stack_a->top / 2)
			{
				rev_rotate_stack(stack_a);
				register_ops("rra\n", ops);
			}
			else
			{
				rotate_stack(stack_a);
				register_ops("ra\n", ops);
			}
		}
		while (peek(stack_b) != value_top_b)
		{
			if (value_top_b == -1)
				break;
			if (steps_stack_b > stack_b->top / 2)
			{
				rev_rotate_stack(stack_b);
				register_ops("rrb\n", ops);
			}
			else
			{
				rotate_stack(stack_b);
				register_ops("ra\n", ops);
			}
		}
		push(stack_a, pop(stack_b));
		register_ops("pa\n", ops);
		
	}
	while (stack_a->numbers[0] != largest_stack_a)
	{
		if (find_steps_to_top(stack_a, largest_stack_a) > stack_a->top / 2)
		{
			rev_rotate_stack(stack_a);
			register_ops("rra\n", ops);
		}
		else 
		{
			rotate_stack(stack_a);
			register_ops("ra\n", ops);
		}
	}
	return (stack_a);
}

int ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}
