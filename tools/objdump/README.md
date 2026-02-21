## Overview

objdump version of "Hello, World!". Build with `make` and run `make disasm` to
disassemble the binary. The `-d` flag shows the machine instructions generated
for each function, including the `greet` and `main` symbols.

## Dependencies

```
gcc
make
binutils (provides objdump)
```
