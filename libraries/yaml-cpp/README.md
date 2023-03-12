## Overview

This program demonstrates the use of the `yaml-cpp` library.

The program performs a traversal through the sample YAML file and then performs
some other operations like grabbing specific keys and iterating through keys.

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

Assuming everything works correctly, you should get output like this:

```
Traversal:
foo
  bar
    fizz
  baz
    buzz
friends
  Alice
    age
      24
  Bob
    age
      25
  Charles
    age
      26
books
    Alice in Wonderland
    The Jungle
    Stranger in a Strange Land
scalar
  1

Friends List:
Alice, age 24
Bob, age 25
Charles, age 26

Picking by Key:
foo->bar=fizz
```
