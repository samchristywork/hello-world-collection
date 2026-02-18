## Overview

AddressSanitizer version of "Hello, World!". The source contains a deliberate
off-by-one heap write (`i <= 5` over a 5-element array). Build with `make` and
run the binary. ASan will catch the overflow and print a detailed report before
the program exits.

## Dependencies

```
gcc
make
```
