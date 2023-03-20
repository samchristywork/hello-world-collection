## Overview

Simple demonstration of `gcov` for a multi-compilation unit program.

## Example

When running `scripts/analyze_coverage.sh`, you should get output like this:

```
$ ./scripts/analyze_coverage.sh
rm -rf build/
mkdir -p build/
gcc -fprofile-arcs -ftest-coverage -g -c src/foo.c -o build/foo.o
mkdir -p build/
gcc -fprofile-arcs -ftest-coverage -g build/foo.o ./src/main.c -lgcov --coverage -o build/main
Hello, World!
Hello, World!
'build/foo.gcno' file is already processed
'build/foo.o' file is already processed
'build/main' file is already processed
'build/main-main.gcda' file is already processed
'build/main-main.gcno' file is already processed
File 'src/foo.c'
Lines executed:100.00% of 3
Creating 'foo.c.gcov'

Lines executed:100.00% of 3
Capturing coverage data from build/
Found gcov version: 12.2.1
Using intermediate gcov format
Using JSON module JSON::PP
Scanning build/ for .gcda files ...
Found 2 data files in build/
Processing build/foo.gcda
Processing build/main-main.gcda
Finished .info-file creation
Reading data file build/coverage.info
Found 2 entries.
Found common filename prefix "/home/sam/git/hello-world-collection/tools/gcov"
Writing .css and .png files.
Generating output.
Processing file src/main.c
Processing file src/foo.c
Writing directory view page.
Overall coverage rate:
  lines......: 75.0% (6 of 8 lines)
  functions..: 66.7% (2 of 3 functions)
```

You can view the `build/index.html` page in an internet browser like Firefox to
see the results.

## Dependencies

```
gcc
lcov // Includes gcov
make
```
