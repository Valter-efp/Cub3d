#!/bin/bash

# Path to cub3D
BINARY="./cub3D"

# Directory containing the maps, do twice for good and bad maps
MAP_DIR="./maps/bad"

# Loop through all .cub files in the maps/good directory
for map_file in "$MAP_DIR"/*.cub; do
	echo "Running Valgrind on $map_file..."
	/usr/bin/valgrind --leak-check=full -s --show-leak-kinds=all "$BINARY" "$map_file"
	if [ $? -eq 0 ]; then
		echo "Valgrind test passed for $map_file"
	else
		echo "Valgrind test failed for $map_file"
	fi
	echo "------------------------------------"
done
