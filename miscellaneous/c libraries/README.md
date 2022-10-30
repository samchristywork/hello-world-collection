## Object Files

Archives are a collection of object files. To create object files with `gcc`,
pass the `-c` option like so:

```
gcc -c libhello.c -o libhello.o
```

## Creating Shared Object Files

`.so` files can be created using `gcc` and passing the `-shared` argument. `gcc`
can also pass arguments to the linker using the `-Wl` argument, which we can use
to set the name of the shared library (`soname`). We also need to pass the
object files to `gcc`.

```
gcc -shared -Wl,-soname,libhello.so -o libhello.so libhello.o
```

## Using Shared Object Files

To use this file, just pass liking flags to `gcc` like you would any other
library:

```
gcc main.c -L build/ -o build/hello -lhello
```

Now you have a compiled program, but if you try to run it it will probably give
you an error like this:

```
./hello: error while loading shared libraries: libhello.so: cannot open shared object file: No such file or directory
```

Digging in deeper, we can see that the linker can't see our library. At runtime,
the linker searches for our library in several places on the system including
`/lib`. `/usr/lib`, and the architecture specific variants. A result of "not
found" means that the library was not found on the library path.

```
ldd hello:
        linux-vdso.so.1 (0x00007ffefb53e000)
        libhello.so => not found
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f594f535000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f594f73d000)
```

In order to use this library, we can either put it in one of the directories
that the linker uses, or add a new directory using `LD_LIBRARY_PATH`. This can
be done like so:

```
LD_LIBRARY_PATH=./path/to/lib ./hello
```

## Listing Symbols in a Library

We can use `nm` to list the symbols that our library exposes:

```
nm -gD build/libhello.so
                 w __cxa_finalize@GLIBC_2.2.5
                 w __gmon_start__
0000000000001105 T hello
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 U puts@GLIBC_2.2.5
```

## Further Reading

<a href="TLDP link">https://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html</a>.
