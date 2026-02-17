## Overview

Autotools version of "Hello, World!". The GNU Autotools suite (`autoconf` and
`automake`) generates a portable `configure` script from `configure.ac` and
`Makefile.am`. Run the following commands to compile the program:

```
autoreconf -i
./configure
make
```

## Dependencies

```
autoconf
automake
gcc
make
```
