#!/bin/bash
set -e

echo "=== 1. Configuring and building targets ==="
cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug
cmake --build build

echo -e "\n=== 2. Running Valgrind on all variants ==="

targets=("dsu_working" "dsu_no_destructor" "dsu_no_copy_constructor" "dsu_no_move_constructor")

for target in "${targets[@]}"; do
    echo "----------------------------------------"
    echo "Running Valgrind on: $target"
    echo "----------------------------------------"
    
    valgrind --leak-check=full  ./build/$target
    
    echo ""
done

echo "=== All Valgrind checks passed successfully! ==="