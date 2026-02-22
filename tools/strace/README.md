## Overview

strace version of "Hello, World!". Build with `make` and trace syscalls with
`make strace`. strace shows every system call the process makes, which reveals
what the C runtime and standard library do under the hood for a simple program.

## Dependencies

```
gcc
make
strace
```
