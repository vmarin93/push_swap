#include "push_swap.h"
#include <limits.h>

void	push_to_b(Stack *stack_a, Stack *stack_b, char **ops)
{
	long	average;
	while (stack_a->top >= 5)
	{
		average = (stack_sum(stack_a) / (stack_a->top + 1));
		if (peek(stack_a) > average)
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
}

int	*get_pairs(Stack *stack_a, Stack *stack_b)
{
	int	*pairs;
	int	i;
	int	j;

	pairs = malloc(sizeof(int) * (2 * stack_b->top));
	if (pairs == NULL)
		return (NULL);
	i = 0;
	j = stack_b->top;
	while (j >= 0)
	{
		pairs[i] = stack_b->numbers[j];
		i++;
		if (find_pair(stack_b->numbers[j], stack_a) != -1)
		{
			pairs[i] = find_pair(stack_b->numbers[j], stack_a);
			i++;
		}
		j--;
	}
	return (pairs);
}

void	fill_go_top_box(Stack *stack_a, Stack *stack_b, int *pairs, Box *go_top)
{
	int	total_steps;
	int	current_steps_a;
	int	current_steps_b;
	int	i;

	total_steps = INT_MAX;
	i = 0;
	while (i < (2 * stack_b->top) - 1)
	{
		current_steps_a = find_steps_to_top(stack_a, pairs[i + 1]);
		current_steps_b = find_steps_to_top(stack_b, pairs[i]);
		if ((current_steps_a + current_steps_b) < total_steps)
		{
			go_top->value_top_a = pairs[i + 1];
			go_top->value_top_b = pairs[i];
			go_top->steps_top_a = current_steps_a;
			go_top->steps_top_b = current_steps_b;
			total_steps = current_steps_a + current_steps_b;
		}
		i += 2;
	}
}

//void	push_to_a(Stack *stack_a, Stack *stack_b, char **ops)
//{
//	int	*pairs;
//	Box	go_top;
//
//	pairs = get_pairs(stack_a, stack_b);
//	fill_go_top_box(stack_a, stack_b, pairs, &go_top);
//	free(pairs);
//}

Stack *sort_large_stack(Stack *stack_a, Stack *stack_b, char **ops)
{
	push_to_b(stack_a, stack_b, ops);
	sort_size_5(stack_a, stack_b, ops);
//	push_to_a(stack_a, stack_b, ops);
	return (stack_a);
}

Stack *sort_stack(Stack *stack_a, Stack *stack_b, char **ops)
{
	if (is_sorted(stack_a))
		return (stack_a);
	else if (stack_a->top == 0)
		return(stack_a);
	else if (stack_a->top == 1)
	{
		if (stack_a->numbers[stack_a->top] > stack_a->numbers[0])
		{
			swap_top(stack_a);
			register_ops("sa\n", ops);
		}
	}
	else if (stack_a->top == 2)
		sort_size_3(stack_a, ops);
	else if (stack_a->top == 3)
		sort_size_4(stack_a, stack_b, ops);
	else if (stack_a->top == 4)
		sort_size_5(stack_a, stack_b, ops);
	else
		sort_large_stack(stack_a, stack_b, ops);
	return (stack_a);
}
