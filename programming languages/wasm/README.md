## Overview

WebAssembly Text Format (WAT) version of "Hello, World!". WAT is the
human-readable form of the WebAssembly binary format. This example calls the
WASI `fd_write` syscall directly to write to stdout, with no toolchain or
language runtime in between. Build with `make` and run with `make run`.

## Dependencies

```
make
wasmtime
wabt (provides wat2wasm)
```
