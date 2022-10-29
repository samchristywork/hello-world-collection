## Object Files

Archives are a collection of object files. To create object files with `gcc`,
pass the `-c` option like so:

```
gcc -c libhello.c -o libhello.o
```

## Creating Archives

Archives can be created using the `ar` utility. Archives are a collection of one
or more object files, and traditionally have the `.a` extension. The following
command will create an archive file from an object file:

```
ar rv libhello.a libhello.o
```

Archive indices can be created using the `ranlib` utility:

```
ranlib libhello.a
```

## Using Archives

Archives can be used like other libraries like so:

```
gcc main.c -L path/to/lib/ -lhello -o main
```
