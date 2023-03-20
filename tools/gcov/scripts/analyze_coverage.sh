#!/bin/bash

make clean
make coverage
./build/main
gcov src/main.c -o build/*
lcov --capture --directory build/ --output-file build/coverage.info
genhtml build/coverage.info --output-directory build/
mkdir -p gcov
mv *.gcov gcov/
firefox build/index.html
