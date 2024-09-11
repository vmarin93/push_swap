#!/bin/bash

# Initialize variables
total=0
min=1000000  # Set to a high number initially
max=0
runs=500

# Function to generate random input
generate_input() {
    seq 1 100 | shuf
}

# Run the program 500 times
for i in $(seq 1 $runs); do
    # Generate random input and run push_swap
    input=$(generate_input)
    output=$(./push_swap $input)
    
    # Count the number of operations (lines)
    count=$(echo "$output" | wc -l)
    
    # Update total, min, and max
    total=$((total + count))
    
    if [ "$count" -lt "$min" ]; then
        min=$count
    fi
    
    if [ "$count" -gt "$max" ]; then
        max=$count
    fi
    
    echo "Run $i: $count operations"
done

# Calculate average
average=$(echo "scale=2; $total / $runs" | bc)

# Print results
echo "Results after $runs runs:"
echo "Average operations count: $average"
echo "Minimum operations count: $min"
echo "Maximum operations count: $max"
