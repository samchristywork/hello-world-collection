## Overview

A simple program showing how signal handlers work in the Linux API.

## Dependencies

```
gcc
make
```

## Usage

Simply run the program with `./build/hello`. The program will stay running until
the user sends SIGQUIT (ctrl-\) to stop it.

Try sending SIGINT with ctrl-c a few times.
