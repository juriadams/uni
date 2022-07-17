#!/bin/bash

rm -rf out/
mkdir out out/i out/ii

echo "building..."

gcc -fdiagnostics-color=always -g src/i/simple.c -o out/i/simple
gcc -fdiagnostics-color=always -g src/i/advanced.c -o out/i/advanced

gcc -fdiagnostics-color=always -g src/ii/cli.c -o out/ii/cli

echo "build done"
