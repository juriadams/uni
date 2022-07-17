#!/bin/bash

echo "building `src/*.c` to `out/*`"

gcc -fdiagnostics-color=always -g src/simple.c -o out/simple
gcc -fdiagnostics-color=always -g src/advanced.c -o out/advanced

echo "built `src/*.c` successfully"
