## Overview

clang-tidy version of "Hello, World!". The source uses `strcpy` into a
fixed-size buffer, which the `clang-analyzer-security.insecureAPI.strcpy` check
flags. Run `make tidy` to see the warning without compiling the program.

## Example

```
$ make tidy
clang-tidy hello.c --checks=clang-analyzer-* -- -Wall
1 warning generated.
hello.c:6:3: warning: Call to function 'strcpy' is insecure as it does not provide bounding of the memory buffer. Replace unbounded copy functions with analogous functions that support length arguments such as 'strlcpy'. CWE-119 [clang-analyzer-security.insecureAPI.strcpy]
    6 |   strcpy(buf, name);
      |   ^~~~~~
hello.c:6:3: note: Call to function 'strcpy' is insecure as it does not provide bounding of the memory buffer. Replace unbounded copy functions with analogous functions that support length arguments such as 'strlcpy'. CWE-119
    6 |   strcpy(buf, name);
      |   ^~~~~~
```

## Dependencies

```
clang-tidy
make
```
