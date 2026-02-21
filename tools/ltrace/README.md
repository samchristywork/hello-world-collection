## Overview

ltrace version of "Hello, World!". Build with `make` and trace library calls
with `make ltrace`. Unlike strace (which shows kernel syscalls), ltrace
intercepts calls to shared library functions such as `printf`.

## Example

```
ltrace ./build/hello
puts("Hello, World!")                            = 14
Hello, World!
+++ exited (status 0) +++
```

## Dependencies

```
gcc
make
ltrace
```
