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
void test_do_int_conversion();
void test_check_for_duplicates();
void test_fill_stack();

#endif
