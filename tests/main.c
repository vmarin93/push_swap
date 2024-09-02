#include "tests.h"
#include <stdio.h>

int main()
{
	// Run input validation tests
	printf("\nValidation tests: \n");
	test_do_int_conversion();
	test_check_for_duplicates();
	test_fill_stack();

	// Run auxiliary functions tests
	printf("\nAuxiliary functions tests: \n");
	test_is_sorted();
	test_find_smallest();
	test_find_largest();
	
	// Run sorting tests
	printf("\nSorting tests: \n");
	test_sort_size_2();
	test_sort_size_3();
	printf("\n");
}
