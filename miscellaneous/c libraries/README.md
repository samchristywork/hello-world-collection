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
