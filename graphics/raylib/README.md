## Overview

This is the raylib version of "Hello, World!". It opens a 3D scene containing a
clickable cube. Clicking the cube highlights it with a "BOX SELECTED" label. The
camera can be moved freely with the mouse.

Because raylib is not typically available as a system package, the Makefile
includes a `clone` target that downloads and builds raylib from source before
compiling the example.

## Building

```
make clone
make
```

## Running

```
./build/hello
```

## Dependencies

```
cmake
gcc
git
libGL
make
```
