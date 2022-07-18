#!/bin/bash

echo "running tests..."

gcc -fdiagnostics-color=always -g src/i/test/test.c -o out/i/test && ./out/i/test
gcc -fdiagnostics-color=always -g src/v/test/test.c -o out/v/test && ./out/v/test

echo "tests done"
