#!/bin/bash

echo "running test suite..."

gcc -fdiagnostics-color=always -g src/test/test.c -o out/test && ./out/test
