#!/bin/bash
echo "Running tests..."
if [ -d "tests" ]; then
    for test in tests/*.cpp; do
        if [ -f "$test" ]; then
            g++ -o test_exec "$test" && ./test_exec
            rm -f test_exec
        fi
    done
else
    echo "No tests directory found."
fi
