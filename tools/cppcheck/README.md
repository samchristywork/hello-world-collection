## Overview

cppcheck version of "Hello, World!". The source intentionally omits `free()` on
a heap allocation. Run `make check` to invoke cppcheck and see it report the
memory leak without needing to compile or run the program.

## Example

```
$ make check
cppcheck --enable=all --error-exitcode=1 hello.c
Checking hello.c ...
hello.c:1:2: information: Include file: <stdio.h> not found. Please note: Standard library headers do not need to be provided to get proper results. [missingIncludeSystem]
#include <stdio.h>
 ^
hello.c:2:2: information: Include file: <stdlib.h> not found. Please note: Standard library headers do not need to be provided to get proper results. [missingIncludeSystem]
#include <stdlib.h>
 ^
hello.c:8:3: error: Memory leak: message [memleak]
  return 0;
  ^
nofile:0:0: information: Active checkers: 113/186 (use --checkers-report=<filename> to see details) [checkersReport]

make: *** [Makefile:2: check] Error 1
```

## Dependencies

```
cppcheck
make
```
