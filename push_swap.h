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

Stack *sort_stack(Stack *stack_a, Stack *stack_b, char **ops);

Stack *sort_size_3(Stack *stack_a, char **ops);

Stack *sort_size_4(Stack *stack_a, Stack *stack_b, char **ops);

Stack *sort_size_5(Stack *stack_a, Stack *stack_b, char **ops);

int is_sorted(Stack *stack);

int is_rev_sorted(Stack *stack);

int find_largest(Stack *stack);

int find_smallest(Stack *stack);

int find_steps_to_top(Stack *stack, int value);

void register_ops(char *op, char **ops);

void free_ops(char **ops);

int ft_strlen(const char *str);

int ft_strcmp(const char *str1, const char *str2);

char *ft_strdup(char *str);

long ft_strtol(char *str, char **endptr);

void validate_input(int argc, char *argv[], Stack *stack_a);

void fill_stack(int *input, int len, Stack *stack_a);

int check_for_duplicates(int *input, int len);

int *do_int_conversion(int argc, char *argv[]);

#endif
