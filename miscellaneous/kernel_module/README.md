## Overview

Linux kernel module version of "Hello, World!". When loaded, the module writes
"Hello, World!" to the kernel log via `pr_info`. When unloaded, it writes
"Goodbye, World!". The message can be read with `dmesg`.

Build with `make`, load with `make load`, and unload with `make unload`.

## Dependencies

```
gcc
linux-headers (matching the running kernel)
make
```
