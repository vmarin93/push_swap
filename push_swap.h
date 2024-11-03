/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarin <vmarin@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:09:29 by vmarin            #+#    #+#             */
/*   Updated: 2024/09/11 10:38:32 by vmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct Stack
{
	int	*numbers;
	int	top;
	int	size;
}	t_Stack;

typedef struct Box
{
	int	current_pair;
	int	curr_a;
	int	curr_b;
	int	total_steps;
	int	value_top_a;
	int	value_top_b;
	int	i_a;
	int	i_b;
	int	steps_top_a;
	int	steps_top_b;
}	t_Box;

typedef struct Operations
{
	char	*ops[15000];
	int		count;
}	t_Operations;

// Stack Functions
t_Stack	*create_stack(int size);
void	free_stack(t_Stack *stack);
int		full_stack(const t_Stack *stack);
int		empty_stack(const t_Stack *stack);
long	peek(const t_Stack *stack);
long	push(t_Stack *stack, int number);
long	pop(t_Stack *stack);
long	stack_sum(t_Stack *stack);
long	swap_top(t_Stack *stack);
long	rotate_stack(t_Stack *stack);
long	rev_rotate_stack(t_Stack *stack);
int		is_sorted(t_Stack *stack);
int		is_rev_sorted(t_Stack *stack);
void	fill_stack(int *input, int len, t_Stack *stack_a);

// Sorting Functions
t_Stack	*sort_stack(t_Stack *stack_a, t_Stack *stack_b, t_Operations *ops);
void	sort_size_3(t_Stack *stack_a, t_Operations *ops);
void	sort_size_4(t_Stack *stack_a, t_Stack *stack_b, t_Operations *ops);
void	sort_size_5(t_Stack *stack_a, t_Stack *stack_b, t_Operations *ops);
void	push_to_b(t_Stack *stack_a, t_Stack *stack_b, t_Operations *ops);
void	fill_go_top_box(t_Stack *stack_a, t_Stack *stack_b, t_Box *go_top);
void	m(t_Stack *stack_a, t_Stack *stack_b, t_Box *go_top, t_Operations *ops);
void	move_to_top_a(t_Stack *stack_a, t_Box *go_top, t_Operations *ops);
void	move_to_top_b(t_Stack *stack_b, t_Box *go_top, t_Operations *ops);
int		find_largest(t_Stack *stack);
int		find_smallest(t_Stack *stack);
int		find_steps_to_top(t_Stack *stack, int value);
int		find_index(t_Stack *stack, int value);
int		find_pair(int value, t_Stack *stack);

// Operations Functions
void	register_ops(char *op, t_Operations *ops);
void	print_ops(t_Operations *ops);
void	free_ops(t_Operations *ops);

// Auxiliary Functions
int		ft_isspace(char c);
int		ft_isdigit(char c);
int		ft_strlen(const char *str);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(char *str);
long	ft_strtol(char *str, char **endptr);
char	*ft_split(int start, int end, char *str);

// Input Validation Functions
void	validate_input(int argc, char *argv[], int **input);
int		check_for_duplicates(int *input, int len);
int		get_input_len(char *input_string);
int		*get_input(int argc, char *argv[]);
int		*single_string_input(char *input_string, int len);
long	do_int_conversion(char *arg, int *input);
char	**fill_input_matrix(char *input_string, int len);
void	free_input_matrix(char **input_matrix);
int		*validate_from_array(char *argv1, int len);

#endif
