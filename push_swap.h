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

int full_stack(Stack *stack);

int empty_stack(Stack *stack);

int peek(Stack *stack);

int push(Stack *stack, int number);

int pop(Stack *stack);

#endif
