## Overview

YACC version of "Hello, World!". Build with `make` and run with `./build/hello`.

## Example

Here is a session that shows off how the interpreter works. Each line that is
prepended with a `$` is user input. The output is the text that was entered
followed by a hyphen and the number of words the program detected.

```
$ Two words.
Two words. - 2
$ Three more words.
Three more words. - 3
$ Here are four words.
Here are four words. - 4
$ Finally, I will type five.
Finally, I will type five. - 5
```

## Dependencies

```
bison
gcc
make
```
