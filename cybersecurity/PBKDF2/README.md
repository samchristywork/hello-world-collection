## Overview

This is a small program that demonstrates the usage of OpenSSL's implementation
of the PBKDF2 hashing algorithm. PBKDF2 works just like any other hashing
algorithm. You give it a key and a salt and the algorithm produces a 'unique'
hash. This hash is then used as a key instead of the more sensitive and less
cryptographically secure original plain-text password. This is a great scheme
because the format of a hash function output has much higher entropy than the
user's plain-text password which is likely short, duplicated on multiple
systems, and subject to psychological biases.

The biggest problem with this scheme is that an attacker could simply guess a
bunch of passwords and compute the hashes of those passwords. The attacker then
tries the hashes on the system and can gain access just as easily as if they had
been brute forcing the weak, user-generated passwords. This is were the
iterative nature of PBKDF2 comes in.

PBKDF2 is designed to be run many times in a row (tens or hundreds of thousands
of iterations per call) to get the final hash. Because the algorithm has a known
amount of compute resources to calculate, and the attacker can't just skip doing
the work of hashing the password, we can force the attacker to expend resources
every time they want to guess a password.

The attacker can still try guessing hashes, but calculating a set of hashes that
makes sense to try by using a dictionary attack is now impossible because each
hash takes time (say one CPU-second) to calculate.

Please note that the below code relies on the OpenSSL library, and should be
compiled with -lcrypto.

## Dependencies

```
gcc
libssl-dev
make
```
