## Overview

## Setup

This program depends on the `yaml-cpp` library. Clone and build it like so:

```bash
git clone https://github.com/jbeder/yaml-cpp
cd yaml-cpp/
mkdir build
cd build
cmake ..
make
cd ../../
```

If you have `yaml-cpp` installed on your system and want to use that instead,
you will have to modify `CMakeLists.txt` to reflect that fact, or create
symlinks to simulate that environment.

## Compilation

```bash
mkdir build
cd build
cmake ..
make
./yaml_example
```

## Output
