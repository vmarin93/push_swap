#include "tests.h"
#include <stdio.h>

int main()
{
	// Run input validation tests
	printf("\nValidation tests: \n");
	test_get_input();
	test_get_input_len();
	test_check_for_duplicates();
	test_fill_stack();
	test_fill_input_matrix();
	test_validate_from_array();

	// Run auxiliary functions tests
	printf("\nAuxiliary functions tests: \n");
	test_is_sorted();
	test_find_smallest();
	test_find_largest();
	test_find_steps_to_top();
	test_stack_sum();
	test_find_pair();
	test_ft_strdup();
	test_register_and_free_ops();
	test_ft_split();
	
	// Run sorting tests
	printf("\nSorting tests: \n");
	test_sort_size_2();
	test_sort_size_3();
	test_sort_size_4();
	test_sort_size_5();
	test_push_to_b();
	test_fill_go_top_box();
	test_move_to_top_a();
	test_move_to_top_b();
	test_sort_stack();
	printf("\n");
}
