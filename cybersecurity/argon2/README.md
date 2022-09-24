## Overview

Argon2 is a key derivation function. The algorithm uses memory resources as a
bottleneck to slow attackers who are trying to brute force data hashes.

The following is a small program that demonstrates the usage of the Argon2 key
derivation algorithm. Argon2 works just like any other hashing algorithm. You
give it a key and a salt and the algorithm produces a 'unique' hash. This hash
is then used as a key instead of the more sensitive and less cryptographically
secure original plain-text password. This is a great scheme because the format
of a hash function output has much higher entropy than the user's plain-text
password which is likely short, duplicated on multiple systems, and subject to
psychological biases.

The biggest problem with hashing schemes like this is that an attacker could
simply guess a bunch of passwords and compute the hashes of those passwords. The
attacker then tries the hashes on the system and can gain access just as easily
as if they had been brute forcing the weak, user-generated passwords. This is
were the memory bottleneck comes in.

Argon2 is designed to take a certain amount of memory resources in order to get
the final hash. Because the algorithm requires a known amount of memory
resources to calculate, and the attacker can't just skip doing the work of
hashing the password, we can force the attacker to expend resources every time
they want to guess a password.

The attacker can still try guessing hashes, but calculating a set of hashes that
makes sense to try by using a dictionary attack is now impossible because each
hash takes memory (say 300 MB) to calculate.

Thus even poor user passwords can be made quite secure at the expense of memory
usage, and extra latency for users during authentication.

## Dependencies

```
gcc
git
make
```
