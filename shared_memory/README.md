## Overview

A simple program showing how shared memory works with the Linux API.

## Dependencies

```
gcc
make
```

## Usage

Simply run the server program with `./build/server`. The program will stay
running until user input is supplied.

With the server running, run the client. The client will print out information
read from the server, then exit immediately. The information that it prints out
is only found in the source code for the server. This shows how two processes
can communicate with each other using shared memory.
