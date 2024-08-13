/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:09:29 by vmarin            #+#    #+#             */
/*   Updated: 2024/07/02 16:09:31 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int ft_isspace(char c);
int ft_isdigit(char c);
int ft_strtoi(const char *str, char **endptr);

typedef struct {
	int	*numbers;
	int	top;
	int	size;
}Stack;

Stack *create_stack(int size);

void free_stack(Stack *stack);

int full_stack(const Stack *stack);

int empty_stack(const Stack *stack);

long peek(const Stack *stack);

long push(Stack *stack, int number);

long pop(Stack *stack);

long swap_top(Stack *stack);

long rotate_stack(Stack *stack);

long rev_rotate_stack(Stack *stack);

Stack *sort_size_3(Stack *stack_a, int *op_count);

Stack *sort_size_4(Stack *stack_a, Stack *stack_b, int *op_count);

Stack *sort_size_5(Stack *stack_a, Stack *stack_b, int *op_count);

int is_sorted(Stack *stack);

int is_rev_sorted(Stack *stack);

int find_largest(Stack *stack);

int find_smallest(Stack *stack);

int find_steps_to_top(Stack *stack, int value);

#endif
