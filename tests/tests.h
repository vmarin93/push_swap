#ifndef TESTS_H
# define TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../push_swap.h"

// ANSI color codes
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Test framework
#define ASSERT(condition, message) do { \
    if (!(condition)) { \
        fprintf(stderr, ANSI_COLOR_RED "Assertion failed: %s\n" ANSI_COLOR_RESET, message); \
        exit(1); \
    } \
} while (0)

#define TEST_PASS(test_name) printf(ANSI_COLOR_GREEN "PASS: %s\n" ANSI_COLOR_RESET, test_name)
#define TEST_FAIL(test_name) printf(ANSI_COLOR_RED "FAIL: %s\n" ANSI_COLOR_RESET, test_name)

// Validation tests
void	test_get_input();
void	test_get_input_len();
void	test_check_for_duplicates();
void	test_fill_stack();
void	test_fill_input_matrix();
void	test_validate_from_array();

// Sorting tests
void	test_sort_size_2();
void	test_sort_size_3();
void	test_sort_size_4();
void	test_sort_size_5();
void	test_push_to_b();
void	test_fill_go_top_box();
void	test_move_to_top_a();
void	test_move_to_top_b();
void	test_sort_stack();

// Auxiliary functions tests
void	test_is_sorted();
void	test_find_smallest();
void	test_find_largest();
void	test_find_steps_to_top();
void	test_stack_sum();
void	test_find_pair();
void	test_ft_strdup();
void	test_register_and_free_ops();
void	test_ft_split();

#endif
