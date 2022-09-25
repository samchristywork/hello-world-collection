## Overview

Valgrind version of "Hello, World!". Build with `make` and run with `make
valgrind`. Remember to compile with the `-g` flag.

## Example

When running Valgrind, you should get output like this:

```
valgrind ./build/hello
==1234567== Memcheck, a memory error detector
==1234567== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1234567== Using Valgrind-3.16.1 and LibVEX; rerun with -h for copyright info
==1234567== Command: ./build/hello
==1234567==
==1234567==
==1234567== HEAP SUMMARY:
==1234567==     in use at exit: 10 bytes in 1 blocks
==1234567==   total heap usage: 1 allocs, 0 frees, 10 bytes allocated
==1234567==
==1234567== LEAK SUMMARY:
==1234567==    definitely lost: 10 bytes in 1 blocks
==1234567==    indirectly lost: 0 bytes in 0 blocks
==1234567==      possibly lost: 0 bytes in 0 blocks
==1234567==    still reachable: 0 bytes in 0 blocks
==1234567==         suppressed: 0 bytes in 0 blocks
==1234567== Rerun with --leak-check=full to see details of leaked memory
==1234567==
==1234567== For lists of detected and suppressed errors, rerun with: -s
==1234567== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Running with `--leak-check=full` gives the extra context to determine which line
of code allocated the memory that is still in use. In this case, it is line 5:

```
==1234567== 10 bytes in 1 blocks are definitely lost in loss record 1 of 1
==1234567==    at 0x483877F: malloc (vg_replace_malloc.c:307)
==1234567==    by 0x109146: main (hello.c:5)
```

## Dependencies

```
gcc
make
valgrind
```
