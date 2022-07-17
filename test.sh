#!/bin/bash

echo "running tests..."

gcc -fdiagnostics-color=always -g src/i/test/test.c -o out/i/test && ./out/i/test

echo "tests done"
