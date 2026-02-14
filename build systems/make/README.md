## Overview

Make version of "Hello, World!". This example demonstrates common Makefile
features including automatic variables (`$^`, `$<`, `$@`), pattern rules
(`%.o: %.c`), and variable substitution. The source is compiled to an object
file first, then linked into the final binary.

Build with `make` and run with `./build/hello`.

## Dependencies

```
gcc
make
```
