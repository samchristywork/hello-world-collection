This example shows proper usage of the `extern` keyword to enable C/C++
interoperability.

Marking a function as `extern` tells the compiler not to mangle the name when
creating object files.

A normal C++ library function in a shared library without `extern` would look
something like this:

```
nm -gD ./build/libhello.so

...
0000000000001105 T _Z5hellov
...
```

The `_Z5hellov` syntax allows C++ to have multiple functions with the same name
but different function signatures. C does not have this features, so you can use
`extern` to tell the compiler to use the old method of naming function so that
it would look something like this:

```
nm -gD ./build/libhello.so

...
0000000000001105 T hello
...
```
