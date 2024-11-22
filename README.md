### Overview

The `push_swap` project is a sorting algorithm challenge where the goal is to sort a stack of integers with the minimum number of operations. This project is written in C and demonstrates efficient algorithm design and implementation.

### Features

- Efficient sorting of integer stacks using a combination of push, swap, rotate, and reverse rotate operations.
- Handles various stack sizes, optimizing the sorting process for small and large stacks.
- Comprehensive error handling and input validation.

### Compilation and Usage

#### Compilation

To compile the project, run the following command:

```sh
make
```

This will generate the `push_swap` executable.

#### Usage

To use the `push_swap` program, run:

```sh
./push_swap <list_of_integers>
```

Example:

```sh
./push_swap 3 2 1 6 5 8 7 4
```

#### Running Tests

To run the tests, compile the test binary using:

```sh
make test
```

Then, execute:

```sh
./test
```

### Core Logic Behind the Algorithms

- **Push to Stack B**:
  - **Function**: `push_to_b`
  - **Logic**: Divides elements in stack A by pushing elements less than the average to stack B, reducing the problem size.

- **Push to Stack A**:
  - **Function**: `push_to_a`
  - **Logic**: Finds the optimal position to push elements from stack B back to stack A, minimizing the number of operations.

- **Bring Largest to Bottom**:
  - **Function**: `bring_largest_to_bottom`
  - **Logic**: Rotates stack A to position the largest element at the bottom.

- **Sort Small Stacks**:
  - **Functions**: `sort_size_3`, `sort_size_4`, `sort_size_5`
  - **Logic**: Uses hardcoded sorting techniques for stacks of sizes 3, 4, and 5.

- **General Sorting**:
  - **Function**: `sort_stack`
  - **Logic**: Determines the appropriate sorting strategy based on the size of the stack.

### Big O Analysis

- **Push to Stack B**: O(n)
- **Push to Stack A**: O(n^2)
- **Bring Largest to Bottom**: O(n)
- **Sort Small Stacks**: O(1)
- **General Sorting**:
  - Small stacks (≤ 5): O(1)
  - Larger stacks: O(n^2)

### Lessons Learned

- **Algorithm Optimization**: Fine-tuning the algorithm for optimal performance, particularly for larger data sets.
- **Error Handling**: Implementing robust error handling and input validation to manage edge cases.
- **Testing**: Importance of comprehensive testing to ensure the correctness of the algorithm.
