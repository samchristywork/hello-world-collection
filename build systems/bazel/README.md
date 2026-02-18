## Overview

Bazel version of "Hello, World!". Bazel uses a `WORKSPACE` file to define the
project root and `BUILD` files to declare targets. It emphasizes reproducible,
hermetic builds. Build and run with:

```
bazel build //:hello
bazel run //:hello
```

## Dependencies

```
bazel
gcc
```
