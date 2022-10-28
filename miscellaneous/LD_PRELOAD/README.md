This is a demonstration of the `LD_PRELOAD` mechanism on Linux. The base program
is a simple "Hello, World!" program, but we can use `LD_PRELOAD` to override
`write` and substitute it with our own implementation.

## Building

To build the main program and the `so` file used to override `write`, simply
type `make`.

## Running

You can run the program with `./build/hello`. This will print "Hello, World!" to
`stdout`.

If you want to use the alternative version of `write`, then you can invoke the
program like this instead: `LD_PRELOAD=./build/mywrite.so build/hello`, or just
use `make run`.
