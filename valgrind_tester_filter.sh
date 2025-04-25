#!/bin/bash

# Path to cub3D
BINARY="./cub3D"

# Directory containing the maps, do twice for good and bad maps
MAP_DIR="./maps/bad"

# Flag to track if any leaks were detected
leaks_detected=false

# Loop through all .cub files in the maps directory
for map_file in "$MAP_DIR"/*.cub; do
    echo "Running Valgrind on $map_file..."
    
    # Run valgrind and capture all output (stderr & stdout)
    VALGRIND_OUTPUT=$(/usr/bin/valgrind --leak-check=full -s --show-leak-kinds=all "$BINARY" "$map_file" 2>&1)
    
    # Print the entire output for debugging (optional)
    # echo "----- Valgrind Full Output -----"
    # echo "$VALGRIND_OUTPUT"
    
    # Now filter for actual memory leaks (cases with 'definitely lost' or 'indirectly lost')
    LEAKS_FOUND=$(echo "$VALGRIND_OUTPUT" | grep -i "definitely lost\|indirectly lost\|still reachable")

    # Check for leaks based on Valgrind output, and print result
    if [[ -n "$LEAKS_FOUND" ]]; then
        echo "Valgrind test failed for $map_file: Memory leak detected!"
        leaks_detected=true  # Mark that a leak was detected
    else
        echo "Valgrind test passed for $map_file: No leaks found."
    fi
    echo "------------------------------------"
done

# Final status message
if [ "$leaks_detected" = true ]; then
    echo "Test finished: Leaks were detected in some files."
else
    echo "Test finished: No leaks detected in any file. Test successful!"
fi

