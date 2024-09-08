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

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct {
	int	*numbers;
	int	top;
	int	size;
}Stack;

typedef struct {
	int	current_pair;
	int	current_steps_a;
	int	current_steps_b;
	int	total_steps;
	int	value_top_a;
	int	value_top_b;
	int	steps_top_a;
	int	steps_top_b;
}Box;

typedef struct {
	char	*ops[15000];
	int	count;
}Operations;

Stack *create_stack(int size);

void free_stack(Stack *stack);

int full_stack(const Stack *stack);

int empty_stack(const Stack *stack);

long peek(const Stack *stack);

long push(Stack *stack, int number);

long pop(Stack *stack);

long stack_sum(Stack *stack);

long swap_top(Stack *stack);

long rotate_stack(Stack *stack);

long rev_rotate_stack(Stack *stack);

Stack *sort_stack(Stack *stack_a, Stack *stack_b, Operations *ops);

Stack *sort_size_3(Stack *stack_a, Operations *ops);

Stack *sort_size_4(Stack *stack_a, Stack *stack_b, Operations *ops);

Stack *sort_size_5(Stack *stack_a, Stack *stack_b, Operations *ops);

void push_to_b(Stack *stack_a, Stack *stack_b, Operations *ops);

void fill_go_top_box(Stack *stack_a, Stack *stack_b, Box *go_top);

void move_to_top_a(Stack *stack_a, Box *go_top, Operations *ops);

void move_to_top_b(Stack *stack_b, Box *go_top, Operations *ops);

int is_sorted(Stack *stack);

int is_rev_sorted(Stack *stack);

int find_largest(Stack *stack);

int find_smallest(Stack *stack);

int find_steps_to_top(Stack *stack, int value);

int find_index(Stack *stack, int value);

int find_pair(int value, Stack *stack);

void register_ops(char *op, Operations *ops);

void free_ops(Operations *ops);

int ft_strlen(const char *str);

int ft_strcmp(const char *str1, const char *str2);

char *ft_strdup(char *str);

long ft_strtol(char *str, char **endptr);

void validate_input(int argc, char *argv[], Stack *stack_a);

void fill_stack(int *input, int len, Stack *stack_a);

int check_for_duplicates(int *input, int len);

int *do_int_conversion(int argc, char *argv[]);

#endif
