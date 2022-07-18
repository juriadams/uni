#!/bin/bash

rm -rf out/
mkdir out out/i out/ii out/iii out/v

echo "building..."

gcc -fdiagnostics-color=always -g src/i/simple.c -o out/i/simple
gcc -fdiagnostics-color=always -g src/i/advanced.c -o out/i/advanced

gcc -fdiagnostics-color=always -g src/ii/cli.c -o out/ii/cli

gcc -fdiagnostics-color=always -g src/iii/main.c -o out/iii/main

gcc -fdiagnostics-color=always -g src/v/main.c -o out/v/main

echo "build done"
