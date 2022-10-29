This is a demonstration of how to use the `LD_PRELOAD` mechanism on Linux to use
an alternative version of `malloc`.

The alternative version presented here will initialize all new memory with the
value 'a'.

## Building

To build the main program and the `so` file used to override `malloc`, simply
type `make`.

## Running

You can run the program with `./build/hello`. This will print the following (or
something similar) to `stdout`:

```
./build/hello
str[0] = 0
str[1] = 0
str[2] = 0
str[3] = 0
str[4] = 0
str[5] = 0
str[6] = 0
str[7] = 0
str[8] = 0
str[9] = 0
```

If you want to use the alternative version of `malloc`, then you can invoke the
program like this instead: `LD_PRELOAD=./build/mymalloc.so build/hello`, or just
use `make run`.

The output should look like this:

```
LD_PRELOAD=./build/mymalloc.so build/hello
str[0] = 97
str[1] = 97
str[2] = 97
str[3] = 97
str[4] = 97
str[5] = 97
str[6] = 97
str[7] = 97
str[8] = 97
str[9] = 97
Freeing block.
```

## Attribution Notice

The `malloc` and `free` functions in `mymalloc.c` come from <a
href="https://stackoverflow.com/questions/5422061/malloc-implementation">this
Stack Overflow post</a>.
