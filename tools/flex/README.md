## Overview

Flex version of "Hello, World!". The lexer tokenizes input from stdin,
classifying each token as a greeting word, noun, or punctuation. Build with
`make` and pipe input to the binary.

## Example

```
$ echo "Hello, World!" | ./build/hello
GREETING_WORD: Hello
PUNCTUATION: ,
NOUN: World
PUNCTUATION: !
```

## Dependencies

```
flex
gcc
make
```
